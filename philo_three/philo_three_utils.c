/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_test_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:27:41 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:27:44 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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

void	meals_counter(t_param *params, char flag)
{
	int				count;

	count = 0;
	while (count < (params->philonum))
	{
		if (flag == 'w')
			sem_wait(params->eating_times);
		else
			sem_post(params->eating_times);
		count++;
	}
	if (flag == 'w')
		sem_post(params->common);
	return ;
}
