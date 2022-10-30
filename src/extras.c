#include "philo.h"

int	error(char *str)
{
	printf("%s", str);
//	write(2, str, ft_strlen(str));
	return (1);
}

int	error_n(int i)
{
	if (i == 1)
		return (error("Wrong arguments!\n"));
	if (i == 2)
		return (error("Error initializing mutex\n"));
	if (i == 3)
		return (error("Memory fault\n"));
	return (1);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (!str)

		return (0);
	while(str[i])
		i++;
	return (i);
}

long long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
