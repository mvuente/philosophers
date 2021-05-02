/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:45 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/21 13:44:48 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	perpetuum_life(t_philo *guy, int lforknum, int rforknum)
{
	long		tmptime;

	while (1)
	{
		pthread_mutex_lock(&guy->params->fork[lforknum]);
		joint_print(guy, "has taken a fork\n", '0');
		pthread_mutex_lock(&guy->params->fork[rforknum]);
		tmptime = current_time();
		pthread_mutex_lock(&guy->params->printer);
		my_print(tmptime - guy->start, guy->id, "is eating\n");
		pthread_mutex_unlock(&guy->params->printer);
		guy->lunchtime = tmptime;
		my_sleep(guy->params->time_to_eat, guy->lunchtime);
		pthread_mutex_unlock(&guy->params->fork[lforknum]);
		pthread_mutex_unlock(&guy->params->fork[rforknum]);
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
	int			lforknum;
	int			rforknum;

	guy = (t_philo*)somebody;
	rforknum = guy->id;
	if (guy->id == guy->params->philonum)
		rforknum = 0;
	lforknum = guy->id - 1;
	pthread_detach(guy->philothread);
	guy->lunchtime = current_time();
	guy->start = guy->lunchtime;
	if (!(guy->id % 2))
		usleep(500);
	perpetuum_life(guy, lforknum, rforknum);
	return (NULL);
}

int		danzen(t_param *params)
{
	int			count;
	t_philo		*philo;
	pthread_t	death;

	count = 0;
	if (!(philo = init_philo(params)))
		return (ft_free(*params, NULL));
	while (count < params->philonum)
	{
		if (pthread_create(&philo[count].philothread, NULL, life,
			&philo[count]))
			return (ft_free(*params, philo));
		count++;
	}
	if (pthread_create(&death, NULL, death_checker, (void *)philo))
		return (ft_free(*params, philo));
	pthread_join(death, NULL);
	free(philo);
	free(params->fork);
	return (-1);
}
