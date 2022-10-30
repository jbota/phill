/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:29:34 by jbota             #+#    #+#             */
/*   Updated: 2022/03/15 17:13:43 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_mutex_fork(t_data *data)
{
	int	i;

	i = data->nb_philo;
	data->forks = calloc(data->nb_philo, sizeof(t_data));
	if (!data->forks)
		return (3);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (2);
	}
	if (pthread_mutex_init(&(data->status), NULL))
		return (2);
	if (pthread_mutex_init(&(data->check), NULL))
		return (2);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = data->nb_philo;
	data->philos = calloc(data->nb_philo, sizeof(t_data));
	if (!data->philos)
		return (3);
	while (--i >= 0)
	{
		data->philos[i].nph = i;
		data->philos[i].forkr = i;
		data->philos[i].forkl = (i + 1) % data->nb_philo;
		data->philos[i].start_t = 0;
		data->philos[i].n_meals = 0;
		data->philos[i].data = data;
	}
	return (0);
}

static void	exit_threads(t_data *data, t_philos *phil)
{
	int i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(phil[i].philo_th, NULL);

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->status));
}

int	init_threads(t_data *data)
{
	int		i;
	t_philos	*phil;

	i = 0;
	phil = data->philos;
	data->first_time = get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(phil[i].philo_th), NULL, philo, &(phil[i])))
			return (2);
		phil[i].start_t = get_time();
		i++;
	}
	monitor(data, data->philos);
	exit_threads(data, phil);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int	i;

//	memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
		return (error("Number of arguments are wrong\n"));
	if ((i = read_args(argc, argv, &data)))
		return (error_n(i));
	if (init_threads(&data))
		return (error("Error creating the threads\n"));
	return (0);
}
