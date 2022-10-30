/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:38:22 by jbota             #+#    #+#             */
/*   Updated: 2022/03/15 17:13:39 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

struct s_data;

typedef struct s_philos 
{
	int		nph;
	int		forkr;
	int		forkl;
	int		start_t;
	int		n_meals;
	pthread_t	philo_th;
//	pthread_mutex_t	mutex;
	struct s_data	*data;
}			t_philos;

typedef struct s_data 
{
//	int		argc;
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		eat_x_times;
	int		dead;
	int		finish_eat;
	long long	first_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check;
	pthread_mutex_t status;
	t_philos	*philos;
}			t_data;

int		read_args(int argc, char **argv, t_data *data);
int		init_mutex_fork(t_data *data);
int		init_philos(t_data *data);
void		thinking(t_philos *philos);
void		sleeping(t_data *data);
void		eating(t_philos *philos);
int		error(char *str);
int		error_n(int i);
int		ft_strlen(char *str);
long long	get_time(void);
int		ini_threads(t_data *data);
void		status_philo(t_data *data, int status, int nph);
int		check_meal(t_data *data);
void		*philo(void *param);
void		monitor(t_data *d, t_philos *phil);
void		start_eat(t_data *data);


#endif
