# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvuente <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 00:48:09 by mvuente           #+#    #+#              #
#    Updated: 2021/01/23 00:48:16 by mvuente          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

SRC = philo_two.c philo_two_utils.c philo_life.c initial.c printers.c errors.c

OBJ = $(SRC:.c=.o)

H = philo_two.h

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
