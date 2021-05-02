# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvuente <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 18:27:06 by mvuente           #+#    #+#              #
#    Updated: 2021/01/19 18:27:15 by mvuente          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRC = philo_three.c philo_three_utils.c philo_life.c initial.c errors.c \
	life_details.c printers.c processes.c finisher.c

OBJ = $(SRC:.c=.o)

H = philo_three.h

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
