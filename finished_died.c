/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:25:48 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/18 17:39:02 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finished_or_died_continue(t_philo *philo, t_data *data)
{
	int			i;
	long long	current_time;

	i = 0;
	while (i < data->nbr_philo)
	{
		current_time = ft_time_in_ms();
		pthread_mutex_lock(&data->mutex);
		if ((current_time - philo[i].last_eat) > data->die_time)
		{
			terminal_msg(data, i, "died");
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

//usleep (100);, per controllare --tool=helgrind
void	finished_or_died(t_philo *philo, t_data *data)
{
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
		finished_or_died_continue(philo, data);
	}
}

int	ft_check_fork(int l, int r)
{
	if (l < r)
		return (l);
	return (r);
}

int	ft_check_fork01(int l, int r)
{
	if (l < r)
		return (r);
	return (l);
}
