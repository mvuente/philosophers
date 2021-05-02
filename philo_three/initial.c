/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:26:14 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:26:18 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			initial(t_param *params, int count, char **param_arr)
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
	if (count == 6)
	{
		if ((params->number_of_times_each_philosopher_must_eat =
			atoi_spec(param_arr[5])) < 0)
			return (0);
	}
	if (!params->number_of_times_each_philosopher_must_eat)
		exit(0);
	ft_unlink();
	ft_open(&params);
	params->death_flag = 0;
	return (1);
}

t_philo		*init_philo(t_param *params, t_philo *philo)
{
	int		count;
	t_philo	*tmp;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * (1 + params->philonum))))
		init_error();
	tmp = philo + params->philonum * sizeof(t_philo);
	tmp = NULL;
	count = 0;
	while (count < params->philonum)
	{
		philo[count].lunchtime = current_time();
		philo[count].id = count + 1;
		philo[count].params = params;
		count++;
	}
	return (philo);
}
