/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:28:23 by mvuente           #+#    #+#             */
/*   Updated: 2021/01/19 18:28:27 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pthread.h>
# include <signal.h>

typedef struct			s_param
{
	int					philonum;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					death_flag;
	sem_t				*fork;
	sem_t				*printer;
	sem_t				*common;
	sem_t				*eating_times;
}						t_param;

typedef struct			s_philo
{
	int					id;
	long				lunchtime;
	long				start;
	sem_t				*ind_eat;
	t_param				*params;
}						t_philo;

void					ft_unlink(void);
void					ft_close(t_param *params);
void					free_and_close(t_philo *philo, int *philoid,
						t_param *params);
void					init_error(void);
void					syst_error(void);
void					fork_error(int *philoid, int count, char flag);
void					ft_putstr(char *arg);
void					ft_open(t_param **params);
void					meals_counter(t_param *params, char flag);
void					ft_killer(t_param *params, int *philoid);
void					perpetuum_life(t_philo *guy);
int						life(void *guy);
void					joint_print(t_philo *guy, char *string, char flag);
void					pure_print(int time, int id, char *string);
void					my_sleep(long sleeptime, long starttime);
long					current_time(void);
int						atoi_spec(char *arg);
int						initial(t_param *params, int count, char **param_arr);
int						danzen(t_param *params);
int						*ft_fork(t_param *params, t_philo *philo);
t_philo					*init_philo(t_param *params, t_philo *philos);
pthread_mutex_t			take_fork(t_philo philo, char symb);
void					my_putnbr(int nbr);

#endif
