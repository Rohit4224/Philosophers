/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:13:09 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/04/15 16:43:52 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;		
	}
	return (0);
}

int check_input(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (check_digit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}