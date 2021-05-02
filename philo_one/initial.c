/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:18 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/21 13:44:21 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		atoi_spec(char *arg)
{
	char	*tmp;
	long	res;

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

int		mut_init(t_param **params)
{
	int		num;

	if (!((*params)->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) *
		((*params)->philonum))))
		return (2);
	num = 0;
	while (num < (*params)->philonum)
	{
		if (pthread_mutex_init(&(*params)->fork[num], NULL))
			return (2);
		num++;
	}
	if (pthread_mutex_init(&(*params)->printer, NULL))
		return (2);
	return (0);
}

int		initial(t_param *params, int count, char **param_arr)
{
	if ((params->philonum = atoi_spec(param_arr[1])) <= 0)
		return (-1);
	if ((params->time_to_die = atoi_spec(param_arr[2])) <= 0)
		return (-1);
	if ((params->time_to_eat = atoi_spec(param_arr[3])) <= 0)
		return (-1);
	if ((params->time_to_sleep = atoi_spec(param_arr[4])) <= 0)
		return (-1);
	params->number_of_times_each_philosopher_must_eat = -1;
	params->meal_flag = -1;
	if (count == 6)
	{
		if ((params->number_of_times_each_philosopher_must_eat =
			atoi_spec(param_arr[5])) < 0)
			return (-1);
		params->meal_flag = params->philonum;
	}
	if (!params->number_of_times_each_philosopher_must_eat)
		return (1);
	params->death_flag = 0;
	return (mut_init(&params));
}

t_philo	*init_philo(t_param *params)
{
	int			count;
	t_philo		*tmp;
	t_philo		*philo;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * (1 + params->philonum))))
		return (NULL);
	tmp = philo + params->philonum * sizeof(t_philo);
	tmp = NULL;
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
