/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:47:35 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:47:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	init_error(void)
{
	write(1, "An initial error\n", 17);
	return (-1);
}

int	ft_unlink_init_error(void)
{
	ft_unlink();
	return (init_error());
}

int	ft_free(t_philo *philo)
{
	free(philo);
	return (init_error());
}
