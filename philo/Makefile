# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 14:05:30 by rkhinchi          #+#    #+#              #
#    Updated: 2023/05/18 17:39:05 by rkhinchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			= main.c utilities.c ft_init.c actions.c threads.c finished_died.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
LIBS			= -lpthread

NAME			= philo

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(all)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
