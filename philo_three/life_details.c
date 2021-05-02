/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_detailes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:26:29 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:26:32 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	eating_process(t_philo **guy)
{
	long	tmptime;

	tmptime = current_time();
	sem_wait((*guy)->params->printer);
	if (!(*guy)->params->death_flag)
	{
		pure_print(tmptime - (*guy)->start, (*guy)->id, "is eating\n");
		(*guy)->lunchtime = tmptime;
	}
	sem_post((*guy)->params->printer);
	my_sleep((*guy)->params->time_to_eat, (*guy)->lunchtime);
	sem_post((*guy)->params->fork);
	sem_post((*guy)->params->fork);
	return ;
}

void	perpetuum_life(t_philo *guy)
{
	while (1)
	{
		if (guy->params->death_flag)
		{
			sem_post(guy->params->eating_times);
			exit(0);
		}
		sem_wait(guy->params->fork);
		joint_print(guy, "has taken a fork\n", '0');
		sem_wait(guy->params->fork);
		eating_process(&guy);
		guy->params->number_of_times_each_philosopher_must_eat--;
		if (!guy->params->number_of_times_each_philosopher_must_eat)
		{
			sem_post(guy->params->eating_times);
			sem_wait(guy->params->common);
			exit(0);
		}
		joint_print(guy, "is sleeping\n", 's');
		joint_print(guy, "is thinking\n", '0');
	}
	return ;
}
