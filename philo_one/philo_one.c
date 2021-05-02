/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:44:55 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/21 13:44:58 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		main(int argc, char **argv)
{
	t_param		params;
	int			init_res;

	if (argc < 5 || argc > 6 || (init_res = initial(&params, argc, argv)) < 0)
	{
		ft_putstr("Wrong number or value of arguments. Error\n");
		return (1);
	}
	if (init_res == 1)
		return (0);
	else if (init_res == 2)
		return (ft_free(params, NULL));
	if ((init_res = danzen(&params)) == 1)
	{
		ft_putstr("System error\n");
		return (1);
	}
	return (0);
}
