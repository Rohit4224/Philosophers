/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:43:49 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/18 17:39:04 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

// data of dinner...

struct	s_philo;

typedef struct s_data
{
	long long			time_of_start;
	int					nbr_philo;
	int					nbr_2_eat;
	int					sleep_time;
	int					die_time;
	int					eat_time;
	int					finihsed_eat;
	int					finished;
	int					dead;
	pthread_mutex_t		lock;
	pthread_mutex_t		mutex;
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

//initialization
void		ft_init(t_data *data, char **argv, int argc);

//threads & routine
void		ft_philo_threads(t_philo *philo, t_data *data);
void		finished_or_died(t_philo *philo, t_data *data);
void		*routine_philo(void *info);
void		threads_free(t_philo *philo, t_data *info);

//actions
void		use_two_forks(t_philo *philo, t_data *info);
void		pause_time(t_data *info, long long wait_time);
void		sleep_and_think(t_philo *philo, t_data *info);
void		terminal_msg(t_data *info, int id, char *message);

//utilities
long long	ft_time_in_ms(void);
int			ft_atoi(char *str);
void		error_msg(char *msg);
int			ft_check_fork01(int l, int r);
int			ft_check_fork(int l, int r);

#endif
