/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:43:49 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/04/25 17:01:50 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

// data of dinner...

struct s_philo;

typedef struct s_data
{
	long long			creation_time;
	int					nbr_philo;
	int					nbr_2_eat;
	int					sleep_time;
	int					die_time;
	int					eat_time;
	int					finihsed_eat;
	int					finished;
	int					dead;
	t_philo				*philos;
	pthread_mutex_t		lock;
	pthread_mutex_t		msg;
	pthread_mutex_t		*forks;
}	t_data;

//information of philosophers

typedef struct s_philo
{
	struct s_data	*info;
    pthread_t		thread;
	long long		last_eat;
    int				id;
    int				right;
    int				left;
    int				eat_count;
}		t_philo;

int			check_input(char **argv);
void		ft_init(t_data *data, char **argv, int argc);
long long	get_time_in_ms(void);
int			ft_atoi(char *str);
void		error_msg(char *msg);

#endif
