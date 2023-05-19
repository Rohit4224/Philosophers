/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:11:43 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/19 17:27:49 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (1);
	return (0);
}

int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 5 && argc != 6)
	{
		if (argc < 5)
			error_msg("Atleast 5 arguments are needed");
		else if (argc > 6)
			error_msg("only 6 arguments are needed\n");
	}
	if (check_input(argv) != 0)
		error_msg("Enter the digit");
	memset(&data, 0, sizeof(t_data));
	ft_init(&data, argv, argc);
}
