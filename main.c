/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:11:43 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/05/15 17:33:06 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		printf("Enter the digit\n");
	memset(&data, 0, sizeof(t_data));
	//data.finished = 0;
	ft_init(&data, argv, argc);
}
