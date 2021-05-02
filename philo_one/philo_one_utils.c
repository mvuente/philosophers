/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:45:22 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/21 13:45:26 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	current_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + (long)(time.tv_usec) / 1000);
}

void	my_sleep(long sleeptime, long starttime)
{
	while ((current_time() - starttime) < sleeptime)
		usleep(500);
	return ;
}

int		ft_free(t_param params, t_philo *philo)
{
	if (params.fork)
		free(params.fork);
	if (philo)
		free(philo);
	ft_putstr("System error\n");
	return (1);
}

int		ft_death(long timedif, t_philo philo, long ttime)
{
	if (timedif >= philo.params->time_to_die)
	{
		pthread_mutex_lock(&philo.params->printer);
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
		pthread_mutex_lock(&philo.params->printer);
		return (0);
	}
	return (1);
}
