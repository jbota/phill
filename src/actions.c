#include "philo.h"

void	eating(t_philos *philos)
{
	t_data *data;

	data = philos->data;
	pthread_mutex_lock(&data->forks[philos->forkr]);
	status_philo(data, FORK, philos->nph);
	pthread_mutex_lock(&data->forks[philos->forkl]);
	status_philo(data, FORK, philos->nph);
	pthread_mutex_lock(&(data->check));
	status_philo(data, EATING, philos->nph);
	data->first_time = get_time();
	pthread_mutex_unlock(&(data->check));
	while (!data->dead)
	{
		if ((get_time() - data->first_time) >= data->time_eat)
			break ;
		usleep(50);
	}
	(philos->n_meals)++;
	pthread_mutex_unlock(&(data->forks[philos->forkr]));
	pthread_mutex_unlock(&(data->forks[philos->forkl]));
}

void	sleeping(t_data *data)
{
	long long	start_sleep;

	start_sleep = get_time();
	while (!data->dead)
	{
	       if ((get_time() - start_sleep) >= data->time_sleep)
		       break ;
		usleep(50);
	}
}

void	thinking(t_philos *philos)
{
	t_data *data;

	data = philos->data;
	status_philo(data, THINKING, philos->nph);
}
