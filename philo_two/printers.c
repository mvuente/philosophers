/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:49:31 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:49:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_putstr(char *arg)
{
	while (*arg != 0x0)
	{
		write(1, arg, 1);
		arg++;
	}
	return ;
}

void	my_putnbr(int nbr)
{
	char	tmp;

	if (nbr >= 0 && nbr < 10)
	{
		tmp = '0' + nbr;
		write(1, &tmp, 1);
	}
	else if (nbr >= 10)
	{
		my_putnbr(nbr / 10);
		tmp = '0' + nbr % 10;
		write(1, &tmp, 1);
	}
	return ;
}

void	my_print(int time, int philo, char *string)
{
	my_putnbr(time);
	write(1, " ", 1);
	my_putnbr(philo);
	write(1, " ", 1);
	ft_putstr(string);
	return ;
}

void	joint_print(t_philo *guy, char *string, char flag)
{
	long	tmptime;

	tmptime = current_time();
	sem_wait(guy->params->pr);
	my_putnbr(tmptime - guy->start);
	write(1, " ", 1);
	my_putnbr(guy->id);
	write(1, " ", 1);
	ft_putstr(string);
	sem_post(guy->params->pr);
	if (flag == 's')
		my_sleep(guy->params->time_to_sleep, tmptime);
	return ;
}
