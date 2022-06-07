/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:30:46 by jbota             #+#    #+#             */
/*   Updated: 2022/03/15 15:24:59 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *s)
{
	int		sign;
	long	r;
	long	i;

	i = 0;
	r = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (s[i] && (s[i] >= 48) && (s[i] <= 57))
	{
		r = (r * 10) + (s[i++] - 48);
	}
	r = sign * r;
	return (r);
}
void	read_args(int argc, char **argv, t_data data)
{
	int 	i;

	i = 0;
	if (data.nb_philo = ft_atoi(argv[1]) <= '0')
		printf("It is necessary at least 1 Philosofer\n");	
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		if (data.eat_x_times = ft_atoi(argv[5])  < 1)
			printf("Each philosopher should it one time\n")
	data.nb_forks = data.nb_philo;
}
