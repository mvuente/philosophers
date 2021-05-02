/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:47:53 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:47:56 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		initial(t_param *params, int count, char **param_arr)
{
	if ((params->philonum = atoi_spec(param_arr[1])) <= 0)
		return (0);
	if ((params->time_to_die = atoi_spec(param_arr[2])) <= 0)
		return (0);
	if ((params->time_to_eat = atoi_spec(param_arr[3])) <= 0)
		return (0);
	if ((params->time_to_sleep = atoi_spec(param_arr[4])) <= 0)
		return (0);
	params->number_of_times_each_philosopher_must_eat = -1;
	params->meal_flag = -1;
	if (count == 6)
	{
		if ((params->number_of_times_each_philosopher_must_eat =
			atoi_spec(param_arr[5])) < 0)
			return (0);
		params->meal_flag = params->philonum;
	}
	if (!params->number_of_times_each_philosopher_must_eat)
		return (1);
	params->death_flag = 0;
	return (2);
}

void	ft_unlink(void)
{
	sem_unlink("fo");
	sem_unlink("pr");
	return ;
}

int		ft_open(t_param *params)
{
	sem_t	*fork;
	sem_t	*print;

	ft_unlink();
	if ((fork = sem_open("fo", O_CREAT, S_IRWXU,
		(unsigned int)params->philonum)) == SEM_FAILED)
		return (init_error());
	if ((print = sem_open("pr", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
	{
		sem_close(params->fo);
		return (ft_unlink_init_error());
	}
	params->fo = fork;
	params->pr = print;
	return (2);
}

t_philo	*init_philo(t_param *params)
{
	int		count;
	t_philo	*philo;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * params->philonum)))
		return (NULL);
	count = 0;
	while (count < params->philonum)
	{
		philo[count].lunchtime = current_time();
		philo[count].id = count + 1;
		philo[count].params = params;
		philo[count].meals = -1;
		if (params->number_of_times_each_philosopher_must_eat > 0)
			philo[count].meals = params->
				number_of_times_each_philosopher_must_eat;
		count++;
	}
	return (philo);
}
