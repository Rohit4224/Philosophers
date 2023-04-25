/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:43:31 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/04/25 17:46:55 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data, char **argv, int argc)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->creation_time = get_time_in_ms();
	if (argc == 6)
		data->nbr_2_eat = ft_atoi(argv[5]);
	else
		data->nbr_2_eat = 1;
	if (data->die_time < 0 || data->eat_time < 0 || data->nbr_philo <= 0 || data->sleep_time < 0 || data->nbr_2_eat <= 0)
		error_msg("Invalid Argument");
	return ;    
}

void	ft_init_forks(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_init(&(data->lock), NULL);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!(data->forks))
		error_msg("Malloc Error");
	while (i < data->nbr_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
}

void	ft_init_philo_info (t_data *data)
{
	int 	i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philo);
	if (!(data->philos))
		error_msg("Malloc Error");
	while (i < data->nbr_philo)
	{
		data->philos[i].right = ((i + 1) % data->nbr_philo);
		data->philos[i].id = i;
		data->philos[i].info = data;
		data->philos[i].left = i;
		data->philos[i].eat_count = 0;
		data->philos[i].last_eat = get_time_in_ms();
		i++;
	}
}

void	ft_init(t_data *data, char **argv, int argc)
{
	ft_init_data (data, argv, argc);
	ft_init_forks (data);
	ft_init_philo_info (data);
}

