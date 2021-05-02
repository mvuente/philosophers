/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:45:08 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/21 13:45:12 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct			s_param
{
	int					philonum;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					meal_flag;
	int					death_flag;
	pthread_mutex_t		*fork;
	pthread_mutex_t		printer;
}						t_param;

typedef struct			s_philo
{
	int					id;
	int					meals;
	long				lunchtime;
	long				start;
	pthread_t			philothread;
	t_param				*params;
}						t_philo;

void					ft_putstr(char *arg);
void					*life(void *guy);
void					my_print(int time, int philo, char *string);
void					my_sleep(long sleeptime, long starttime);
void					joint_print(t_philo *guy, char *string, char flag);
void					perpetuum_life(t_philo *guy, int lforknum,
						int rforknum);
int						ft_free(t_param params, t_philo *philo);
long					current_time(void);
int						atoi_spec(char *arg);
int						initial(t_param *params, int count, char **param_arr);
int						danzen(t_param *params);
int						ft_death(long timedif, t_philo philo, long ttime);
int						ft_meals(t_philo philo);
int						mut_init(t_param **params);
t_philo					*init_philo(t_param *params);

#endif
