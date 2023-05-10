/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:43:40 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/10 17:49:14 by rkhinchi         ###   ########.fr       */
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
		usleep(1000);
	else
		usleep (500);
	while (!data->finished)
	{
		use_two_forks(philo, data);
		if (data->nbr_2_eat == philo->eat_count)
		{
			//printf("nbr2eat = %d\n eatCout = %d ",data->nbr_2_eat, philo->eat_count);
			data->finihsed_eat++;
			break ;
		}
		//philo->eat_count = philo->eat_count + 1;
		//write(1, "culo\n", 5);
		sleep_and_think(philo, data);
	}
	return ((void *)0);
}

void	finished_or_died(t_philo *philo, t_data *data)
{
	int			i;
	long long	current_time;

	while (!data->finished)
	{
		if ((data->nbr_2_eat != 0) && (data->nbr_philo == data->finihsed_eat))
		{
			data->finished = 1;
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
				break ;
			}
			i++;
		}
	}
}
