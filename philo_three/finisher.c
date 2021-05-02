/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:25:50 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:26:03 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_killer(t_param *params, int *philoid)
{
	int	count;

	count = 0;
	while (count < params->philonum)
	{
		if (!kill(philoid[count], 0))
			kill(philoid[count], SIGKILL);
		count++;
	}
	return ;
}

void	ft_close(t_param *params)
{
	sem_close(params->fork);
	sem_close(params->printer);
	sem_close(params->common);
	sem_close(params->eating_times);
	return ;
}

void	free_and_close(t_philo *philo, int *philoid, t_param *params)
{
	free(philo);
	free(philoid);
	ft_close(params);
	ft_unlink();
	return ;
}
