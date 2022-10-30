#include "philo.h"

void	status_philo(t_data *data, int status, int nph)
{
	pthread_mutex_lock(&(data->status));
	if (!(data->dead))
	{
		printf("%lli ", get_time() - data->first_time);
		printf("Philo %i ", nph + 1);
		if (status == FORK)
			printf("Has taken one fork\n");
		else if (status == EATING)
			printf("Is eating\n");
		else if (status == THINKING)
			printf("IS thinking\n");
		else if (status == SLEEPING)
			printf("Is sleeping\n");
		else if (status == DIED)
			printf("Just died\n");
	}
	pthread_mutex_unlock(&(data->status));
	return ;
}
