/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:28:38 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:28:44 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*death_checker(void *philo)
{
	int			count;
	t_philo		*tmp;
	long		timedif;
	long		ttime;

	tmp = (t_philo *)philo;
	count = 0;
	while (1)
	{
		ttime = current_time();
		timedif = ttime - (*tmp).lunchtime;
		if (timedif >= (*tmp).params->time_to_die)
		{
			(*tmp).params->death_flag = 1;
			sem_wait((*tmp).params->printer);
			pure_print(ttime - (*tmp).start, (*tmp).id, "is died\n");
			while (count++ < (*tmp).params->philonum)
				sem_post((*tmp).params->eating_times);
			exit(0);
		}
		usleep(10);
	}
}

int		life(void *somebody)
{
	t_philo		*guy;
	pthread_t	death;

	guy = (t_philo*)somebody;
	if (pthread_create(&death, NULL, death_checker, somebody))
	{
		if (guy->params->number_of_times_each_philosopher_must_eat > -1)
			meals_counter(guy->params, 'p');
		exit(1);
	}
	guy->lunchtime = current_time();
	guy->start = guy->lunchtime;
	if (!(guy->id % 2))
		usleep(5000);
	perpetuum_life(guy);
	return (0);
}

int		danzen(t_param *params)
{
	t_philo		*philo;
	int			*philoid;
	int			exi_stat;

	philo = NULL;
	philo = init_philo(params, philo);
	sem_wait(params->common);
	sem_wait(params->eating_times);
	philoid = ft_fork(params, philo);
	if (params->number_of_times_each_philosopher_must_eat > -1)
		meals_counter(params, 'w');
	waitpid(-1, &exi_stat, 0);
	ft_killer(params, philoid);
	free_and_close(philo, philoid, params);
	if (WIFEXITED(exi_stat))
	{
		if (WEXITSTATUS(exi_stat))
			init_error();
		return (0);
	}
	syst_error();
	return (0);
}
