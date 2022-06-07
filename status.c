#include "philo.h"

void	status_philo(t_data *data, int status)
{
	phtread_mutex_lock(&philo->info->status);
	if (philo->info->stop)
	{
		phtread_mutex_nlock(&philo->info->status);
		return ;
	}
	printf("%d\t", get_time() - philo->info->base_time);
	printf("philo %d ", philo->n + 1);
	if (status == FORK)
		printf("Has taken one fork\n");
	else if (status == EATING)
		printf("Is eating\n");
	else if (status == THINKING)
		printf("IS thinking\n");
	else if (status == SLEEPING)
		printf("Is sleeping\n");
	else if (status == DIE)
		printf("just died");
	phread_mutex_unlock(&philo->info->status);
}
