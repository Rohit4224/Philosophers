/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:11:43 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/04/15 16:43:51 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        if (argc < 5)
            printf("Atleast 5 arguments are needed\n");
        else if (argc > 6)
            printf("only 6 arguments are needed\n");
    }
    if (check_input(argv) != 0)
        printf("Enter the digit\n");
}