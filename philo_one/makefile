# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvuente <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 13:43:35 by mvuente           #+#    #+#              #
#    Updated: 2021/01/21 13:43:42 by mvuente          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

SRC = philo_one.c philo_one_utils.c philo_life.c initial.c printers.c

OBJ = $(SRC:.c=.o)

H = philo_one.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

%.o: %.c $(H)
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
