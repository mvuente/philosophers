/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:48:29 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:48:33 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	perpetuum_life(t_philo *guy)
{
	long		tmptime;

	while (1)
	{
		sem_wait(guy->params->fo);
		joint_print(guy, "has taken a fork\n", '0');
		sem_wait(guy->params->fo);
		tmptime = current_time();
		sem_wait(guy->params->pr);
		my_print(tmptime - guy->start, guy->id, "is eating\n");
		sem_post(guy->params->pr);
		guy->lunchtime = tmptime;
		my_sleep(guy->params->time_to_eat, guy->lunchtime);
		sem_post(guy->params->fo);
		sem_post(guy->params->fo);
		if (!--guy->meals && guy->params->meal_flag > 0)
			guy->params->meal_flag--;
		joint_print(guy, "is sleeping\n", 's');
		joint_print(guy, "is thinking\n", '0');
	}
	return ;
}

void	*death_checker(void *philo)
{
	int			count;
	t_philo		*tmp;
	long		timedif;
	long		ttime;
	int			num;

	tmp = (t_philo *)philo;
	num = (*tmp).params->philonum;
	count = 0;
	while (1)
	{
		if (count == num)
			count = 0;
		ttime = current_time();
		timedif = ttime - tmp[count].lunchtime;
		if (!ft_death(timedif, tmp[count], ttime) || !ft_meals(tmp[count]))
			return (NULL);
		usleep(10);
		count++;
	}
}

void	*life(void *somebody)
{
	t_philo		*guy;
	int			tmp;

	tmp = 0;
	guy = (t_philo*)somebody;
	pthread_detach(guy->philothread);
	guy->lunchtime = current_time();
	guy->start = guy->lunchtime;
	if (guy->id % 2)
		usleep(100);
	perpetuum_life(guy);
	return (NULL);
}

int		danzen(t_param *params)
{
	int			count;
	t_philo		*philo;
	pthread_t	death;

	count = 0;
	if (!(philo = init_philo(params)))
		return (init_error());
	while (count < params->philonum)
	{
		if (pthread_create(&philo[count].philothread, NULL, life,
			&philo[count]))
			return (ft_free(philo));
		count++;
	}
	if (pthread_create(&death, NULL, death_checker, (void *)philo))
		return (ft_free(philo));
	pthread_join(death, NULL);
	free(philo);
	return (0);
}
