/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:04:22 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/16 16:11:54 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	use_two_forks(t_philo *philo, t_data *info)
{
	pthread_mutex_lock(&(info->forks[ft_check_fork(philo->left, philo->right)]));
	terminal_msg(info, philo->id, "has taken fork");
	if (info->nbr_philo != 1)
	{
		pthread_mutex_lock(&(info->forks[ft_check_fork01(philo->right, philo->left)]));
		terminal_msg(info, philo->id, "has taken fork");
		terminal_msg(info, philo->id, "is eating");
		philo->last_eat = ft_time_in_ms();
		//philo->eat_count = philo->eat_count + 1;
		pause_time(info, (long long)info->eat_time);
		pthread_mutex_unlock(&(info->forks[philo->right]));
	}
	pthread_mutex_unlock(&(info->forks[philo->left]));
}

void	terminal_msg(t_data *info, int id, char *message)
{
	long long	now;

	now = ft_time_in_ms();
	pthread_mutex_lock(&(info->lock));
	if (!(info->finished))
	{
		printf("%lld ", (now - info->time_of_start));
		printf("%d ", id + 1);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&(info->lock));
}

void	sleep_and_think(t_philo *philo, t_data *info)
{
	terminal_msg(info, philo->id, "is sleeping");
	pause_time(info, (long long)info->sleep_time);
	terminal_msg(info, philo->id, "is thinking");
}

void	pause_time(t_data *info, long long wait_time)
{
	long long	now;
	long long	start;

	start = ft_time_in_ms();
	pthread_mutex_lock(&(info->lock));
	while (!(info->finished))
	{
		now = ft_time_in_ms();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
	pthread_mutex_unlock(&(info->lock));
}

void	threads_free(t_philo *philo, t_data *info)
{
	int	index;

	index = 0;
	while (index < info->nbr_philo)
		pthread_mutex_destroy(&(info->forks[index++]));
	free(philo);
	free(info->forks);
	pthread_mutex_destroy(&(info->lock));
	pthread_mutex_destroy(&(info->mutex));
}
