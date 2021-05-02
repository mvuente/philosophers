/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:29:06 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:29:10 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_unlink_init_error(void)
{
	ft_unlink();
	init_error();
	return ;
}

void	ft_unlink(void)
{
	sem_unlink("/fork");
	sem_unlink("/printer");
	sem_unlink("/eating_times");
	sem_unlink("/ind_eat");
	sem_unlink("/common");
	return ;
}

void	ft_open(t_param **params)
{
	if (((*params)->fork = sem_open("/fork", O_CREAT, S_IRWXU,
		(unsigned int)(*params)->philonum)) == SEM_FAILED)
		init_error();
	if (((*params)->printer = sem_open("/printer", O_CREAT, S_IRWXU, 1))
		== SEM_FAILED)
	{
		sem_close((*params)->fork);
		ft_unlink_init_error();
	}
	if (((*params)->common = sem_open("/common", O_CREAT, S_IRWXU, 1))
		== SEM_FAILED)
	{
		sem_close((*params)->fork);
		sem_close((*params)->printer);
		ft_unlink_init_error();
	}
	if (((*params)->eating_times = sem_open("/eating_times", O_CREAT, S_IRWXU,
		1)) == SEM_FAILED)
	{
		sem_close((*params)->fork);
		sem_close((*params)->printer);
		sem_close((*params)->common);
		ft_unlink_init_error();
	}
	return ;
}

int		*ft_fork(t_param *params, t_philo *philo)
{
	int			count;
	pid_t		p;
	int			*philoid;

	count = -1;
	if (!(philoid = (int*)malloc(sizeof(int) * params->philonum)))
	{
		write(1, "philoid\n", 8);
		init_error();
	}
	while (++count < params->philonum)
	{
		p = fork();
		if (p == 0)
			life(&philo[count]);
		else
		{
			philoid[count] = p;
			if (p < 0)
				fork_error(philoid, count, 'f');
		}
	}
	return (philoid);
}
