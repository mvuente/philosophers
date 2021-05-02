/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:25:31 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:25:39 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	init_error(void)
{
	write(1, "An initial error\n", 17);
	exit(1);
}

void	syst_error(void)
{
	write(1, "Unknown system error\n", 21);
	exit(1);
}

void	fork_error(int *philoid, int num, char flag)
{
	int	count;

	count = 0;
	while (count < num)
	{
		kill(philoid[count], SIGKILL);
		count++;
	}
	if (flag == 't')
		kill(philoid[count], SIGKILL);
	write(1, "A fork initial error\n", 21);
	exit(1);
}
