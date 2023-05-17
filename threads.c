/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:43:40 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/17 17:22:33 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_threads(t_philo *philo, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].last_eat = ft_time_in_ms();
		pthread_create(&(philo[i].thread), NULL, routine_philo, &(philo[i]));
		i++;
	}
	finished_or_died(philo, data);
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	threads_free(philo, data);
}

void	*routine_philo(void *info)
{
	t_data	*data;
	t_philo	*philo;	

	philo = info;
	data = philo->info;
	if (philo->id % 2)
		usleep(1500);
	else
		usleep (800);
	while (1)
	{
		pthread_mutex_lock(&(data->mutex));
		if (data->finished == 1)
		{
			pthread_mutex_unlock(&(data->mutex));
			break ;
		}
		pthread_mutex_unlock(&(data->mutex));
		use_two_forks(philo, data);
		if (data->nbr_philo == 1)
			finished_or_died(philo, data);
		pthread_mutex_lock(&(data->mutex));
		if (data->nbr_2_eat != 0 && philo->eat_count == data->nbr_2_eat)
		{
			data->finihsed_eat++;
			if (data->finihsed_eat == data->nbr_philo)
			{
				data->finished = 1;
				pthread_mutex_unlock(&(data->mutex));
				break ;
			}
		}
		pthread_mutex_unlock(&(data->mutex));
		sleep_and_think(philo, data);
	}
	return ((void *)0);
}


void	finished_or_died(t_philo *philo, t_data *data)
{
	int			i;
	long long	current_time;

	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->finished == 1)
		{
			pthread_mutex_unlock(&data->mutex);
			break ;
		}
		pthread_mutex_unlock(&data->mutex);
		pthread_mutex_lock(&data->mutex);
		if ((data->nbr_2_eat != 0) && (data->nbr_philo == data->finihsed_eat))
		{
			data->finished = 1;
			pthread_mutex_unlock(&data->mutex);
			break ;
		}
		pthread_mutex_unlock(&data->mutex);
		i = 0;
		while (i < data->nbr_philo)
		{
			current_time = ft_time_in_ms();
			pthread_mutex_lock(&data->mutex);
			if ((current_time - philo[i].last_eat) > data->die_time)
			{
				terminal_msg(data, i, "Died");
				pthread_mutex_lock(&(data->lock));
				data->finished = 1;
				pthread_mutex_unlock(&data->lock);
				pthread_mutex_unlock(&data->mutex);
				break ;
			}
			pthread_mutex_unlock(&data->mutex);
			i++;
		}
	}
}

/* void    *routine_philo(void *info)
{
	t_data		*data;
	t_philo		*philo;

	philo = info;
	data = philo->info;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep (500);
	while (1)
	{
		pthread_mutex_lock(&(data->mutex)); // lock mutex
		if (data->finished)
		{
			pthread_mutex_unlock(&(data->mutex)); // unlock mutex
			break ;
		}
		use_two_forks(philo, data);
		philo->eat_count++; // modify eat_count
		if (data->nbr_2_eat != 0 && philo->eat_count == data->nbr_2_eat)
		{
			data->finihsed_eat++;
			if (data->finihsed_eat == data->nbr_philo)
				data->finished = 1; // modify finished
			pthread_mutex_unlock(&(data->mutex)); // unlock mutex
			break ;
		}
		pthread_mutex_unlock(&(data->mutex)); // unlock mutex
		sleep_and_think(philo, data);
	}
	return ((void *)0);
} */

/* void	finished_or_died(t_philo *philo, t_data *data)
{
    int			i;
    long long	current_time;

    while (1)
    {
        pthread_mutex_lock(&data->finished_mutex);
        if (data->finished) // Check if finished flag is set
        {
            pthread_mutex_unlock(&data->finished_mutex);
            break ;
        }
        if ((data->nbr_2_eat != 0) && (data->nbr_philo == data->finihsed_eat))
        {
            data->finished = 1;
            pthread_mutex_unlock(&data->finished_mutex);
            break ;
        }
        i = 0;
        while (i < data->nbr_philo)
        {
            current_time = ft_time_in_ms();
            if ((current_time - philo[i].last_eat) >= data->die_time)
            {
                terminal_msg(data, i, "Died");
                data->finished = 1;
                pthread_mutex_unlock(&data->finished_mutex);
                return ;
            }
            i++;
        }
        pthread_mutex_unlock(&data->finished_mutex);
    }
} */

