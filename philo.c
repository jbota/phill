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

void	init_mutex_fork(t_data data)
{
	int	i;

	i = 0;
	data.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
//	if (!data.nb_forks) check this
	if (!data.forks)
		printf("Unable to allocate memory\n");
	while (i++ < data.nb_philo)
	{
		if (pthread_mutex_init(&data.forks, NULL))
			printf("Unabe to start mutex\n");
	}
}

void	init_philos(t_data data)
{
	int	i;

	i = 0;
	data->philos = (t_data *)malloc(sizeof(t_data) * data.nb_philo);
	if (!data->philos)
		printf("Unable to allocate memory\n");
	while (i++ < data.nb_philos)
	{
		data->philos[i].nph = i;
		data->philos[i].fork = i;
		data->philos[i].forkl = (i + 1) % data.nb_philo;
		data->philos[i].start_t = 0;
		data->philos[i].n_meals = 0;
		data->philos[i].data = data;
		if(pthread_mutex_init(&data.philos[i].mutex, NULL))
			printf("Unable to start mutex\n");
	}
}

void	init_threads(t_data data);
{
	int	i;

	i = 0;
	while (i++ < data.nb_philo)
	{
		if (pthread_create(data->philos[i].phil_th, NULL, &data->philos, NULL) != 0)
			printf("Error creating the thread\n");
	}
	while (i++ < data.nb_philo)
	{
		if (pthread_join(data->philos[i].phil_th, NULL) != 0)
			printf("Unable to join threds\n");
	}
}

int main(int argc, char **argv)
{
	t_data	data;
	int	i;

	memset(&data, 0, sizeof(t_data));
	if (argc != 5 || argc != 6)
		printf("Number of arguments are wrong\n");
	i = 0;
	read_args(argc, argv, data);
	init_mutex_fork(data);
	init_threads(data);

	pthread_mutex_destroy(&data.fork);
	pthread_mutex_destroy(&data->philos.mutex);
	return (0);
}
