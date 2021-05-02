/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:27:52 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:28:14 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		main(int argc, char **argv)
{
	t_param		params;

	if (argc < 5 || argc > 6 || !initial(&params, argc, argv))
	{
		ft_putstr("Wrong number or value of arguments. Error");
		return (1);
	}
	danzen(&params);
	return (0);
}
