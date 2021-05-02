/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:48:46 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:48:50 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + (long)(time.tv_usec) / 1000);
}

int		atoi_spec(char *arg)
{
	char			*tmp;
	long			res;

	res = 0;
	tmp = arg;
	while (*tmp != 0x0)
	{
		if (*tmp < 0x30 || *tmp > 0x39)
			return (-1);
		tmp++;
	}
	while (*arg != 0x0)
	{
		res = *arg - 0x30 + res * 10;
		arg++;
		if (res > INT_MAX)
			return (-1);
	}
	return (res);
}

void	my_sleep(long sleeptime, long starttime)
{
	while ((current_time() - starttime) < sleeptime)
		usleep(500);
	return ;
}

int		ft_death(long timedif, t_philo philo, long ttime)
{
	if (timedif >= philo.params->time_to_die)
	{
		sem_wait(philo.params->pr);
		philo.params->death_flag = 1;
		my_print(ttime - philo.start, philo.id, "is died\n");
		return (0);
	}
	return (1);
}

int		ft_meals(t_philo philo)
{
	if (!philo.params->meal_flag)
	{
		sem_wait(philo.params->pr);
		return (0);
	}
	return (1);
}
