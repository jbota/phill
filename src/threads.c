#include "philo.h"

int	check_meal(t_data *data)
{
	int	i;
//	int	count;

	i = -1;
//	count = 0;
	while (++i < data->nb_philo)
	{
		if (data->philos[i].n_meals < data->eat_x_times)
			return (0);
	}
	data->dead = 1;
	return (1);
}

void	*philo(void *param)
{
	int		i;
	t_data		*data;
	t_philos	*philo;

	i = 0;
	philo = (t_philos *)param;
	data = philo->data;
	if (philo->nph % 2)
		usleep(15000);
	while (!(data->dead))
	{
		eating(philo);
		if (data->finish_eat)
			break ;
		status_philo(data, SLEEPING, philo->nph);
		sleeping(data);
		status_philo(data, THINKING, philo->nph);
//		thinking(philo);
		i++;
	}
	return(NULL);
}

void	monitor(t_data *d, t_philos *phil)
{
	int	i;

	while(!(d->finish_eat))
	{
		i = -1;
		while (++i < d->nb_philo && !(d->dead))
		{
			pthread_mutex_lock(&(d->check));
			if ((get_time() - phil[i].start_t) > d->time_die)
			{
				status_philo(d, DIED, phil->nph);
				d->dead = 1;
			}
			pthread_mutex_unlock(&(d->check));
			usleep(100);
		}
		if (d->dead)
			break ;
		i = 0;
		while (d->eat_x_times != -1 && i < d->nb_philo && phil[i].n_meals >= d->eat_x_times)
			i++;
		if (i == d->nb_philo)
			d->finish_eat = 1;
	}
}

void	start_eat(t_data *data)
{
	int i;

//	data->time = get_time();
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].start_t = get_time();
		if(pthread_create(&data->philos[i].philo_th, NULL, philo, &data->philos[i]))
		{
			printf("Failed to create thread.\n");
			return ;
		}
/*		if (pthread_create(&data->philos[i].monitor, NULL, monitor, &data->philos[i]))
		{
			printf("failed to create thread.\n");
			return ;
		}
*/	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philos[i].philo_th, NULL))
		{	
			printf("Failed to join thread.\n");
			return ;
		}
/*		if (pthread_join(data->philos[i].monitor, NULL))
		{
			printf("Failed to join thread.\n");
			return ;
		}
*/	}
	//return(0);
}
