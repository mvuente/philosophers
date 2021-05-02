/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:48:57 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:49:00 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		main(int argc, char **argv)
{
	t_param		params;
	int			init_res;
	int			tmp;

	if (argc < 5 || argc > 6 || !(init_res = initial(&params, argc, argv)))
	{
		ft_putstr("Wrong number or value of arguments. Error");
		return (1);
	}
	if (init_res == 1)
		return (0);
	else if (init_res == -1)
		return (1);
	if ((tmp = ft_open(&params)) == -1)
		return (1);
	if (danzen(&params))
		return (1);
	ft_unlink();
	return (0);
}
