/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:49:08 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/23 00:49:17 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/stat.h>

typedef struct			s_param
{
	int					philonum;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					death_flag;
	int					meal_flag;
	sem_t				*fo;
	sem_t				*pr;
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

void					ft_unlink(void);
int						ft_open(t_param *params);
void					my_putnbr(int nbr);
void					ft_putstr(char *arg);
void					*life(void *guy);
void					my_print(int time, int philo, char *string);
void					my_sleep(long sleeptime, long starttime);
void					perpetuum_life(t_philo *guy);
void					joint_print(t_philo *guy, char *string, char flag);
long					current_time(void);
int						ft_meals(t_philo philo);
int						ft_death(long timedif, t_philo philo, long ttime);
int						ft_free(t_philo *philo);
int						init_error(void);
int						ft_unlink_init_error(void);
int						atoi_spec(char *arg);
int						initial(t_param *params, int count, char **param_arr);
int						danzen(t_param *params);
t_philo					*init_philo(t_param *params);

#endif
