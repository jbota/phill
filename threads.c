#include "philo.h"

int	check_meal(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < philo->info->num_philo)
	{
		if (philo->info->[i].meals <philo->info->num_must_eat)
			return (0);
	}
	philo->info->stop = 1;
	return (1);
}

void	*philo(void *param)
{
	t_data *philo;

	philo = param;
	if (philo->n % 2 == 0 && philo->info->num_philo != 1)
		usleep(1000 * philo->info->time_eat);
	while (!philo->info->stop)
	{
		eating(philo);
		if (philo->info->n_must_eat != 1 && check_meals(philo))
			break ;
		if (philo->info->stop)
			break ;
		sleeping(philo);
		if (philo->info->stop)
			break ;
		thinkinh(philo);
		if (philo->info->stop)
			break ;
	}
	return(NULL);
}

void	*monitor(void *param)
{
	t_data *philo;

	philo = param;
	while(!philo->info->stop)
	{
		pthread_mutex_lock(&philo->protect);
		if (get_time() - philo->start_time >= philo->info->time_die)
		{
			if (get_time() - philo->start_time >= philo->info->time_die)
			{
				print_status(philo, DIED);
				philo->info->stop = 1;
				phtread_mutex_unlock(&philo->protect);
				break ;
			}
		}
		pthread_mutex_unlock(&philo->protect);
		usleep(100);
	}
	//return(NULL);
}

void	start_eat(t_data data)
{
	int i;

	data->time = get_time();
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].start_time = get_time();
		if(pthread_create(&data->philo[i].philo_th, NULL, philo, &data->philo[i]))
			return (err("Failed to create thread.\n"));
		if (pthread_creat(&info->philo[i].monitor, NULL, monitor, &data->philo[i]))
			return(err("failed to create thread.\n"));
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(info->philo[i].philo_th, NULL))
			return (err("Failed to join thread.\n"));
		if (pthread_joi(data->philo[i].monitor, NULL))
			return (err("Failed to join thread.\n"));
	}
	//return(0);
}
