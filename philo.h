/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:38:22 by jbota             #+#    #+#             */
/*   Updated: 2022/03/15 16:23:16 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_data {

	int				argc;
	unsigned long	nb_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			eat_x_times;
	pthread_mutex_t	*forks;
	t_data			*philos;
}		t_data;

typedef struct s_data {
	int				nph;
	int				fork;
	int				forkl;
	int				start_t;
	int				n_meals;
	phtread_t		phil_th;
	phtread_t		check;
	pthread_mutex_t	mutex;
}	t_philos;

void read_args(int argc, char **argv, t_data data);
void init_mutex_fork(t_dta data);
void init_philos(t_data data);

#endif
