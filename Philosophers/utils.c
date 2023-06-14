/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:25 by joberle           #+#    #+#             */
/*   Updated: 2022/10/11 14:04:29 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	my_usleep(long long time)
{
	long long	real_time;

	real_time = get_time();
	usleep(time * 920);
	while (time > (get_time() - real_time))
		usleep(90);
}

int	print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&(ph->info->mut_print));
	printf("%llu %d %s\n", get_time() - ph->info->start_time, ph->num, str);
	pthread_mutex_unlock(&(ph->info->mut_print));
	return (0);
}

long long int	get_time(void)
{
	struct timeval	t;
	long long int	res;

	gettimeofday(&t, 0);
	res = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (res);
}

void	free_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	free(data->philos);
	data->philos = NULL;
	pthread_mutex_unlock(&(data->mut_e));
	pthread_mutex_destroy(&(data->mut_e));
	pthread_mutex_unlock(&(data->mut_t));
	pthread_mutex_destroy(&(data->mut_t));
	while (i < data->num_of_ph)
	{
		pthread_mutex_unlock(&(data->forks[i]));
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&(data->mut_print));
	free(data->threads);
	free(data);
}
