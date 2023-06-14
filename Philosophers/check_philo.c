/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:03:49 by joberle           #+#    #+#             */
/*   Updated: 2022/10/13 14:20:35 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_ph)
	{
		pthread_mutex_lock(&(data->mut_t));
		if (get_time() - data->philos[i].last_meal_time \
		> (long long)data->time_d)
		{
			pthread_mutex_unlock(&(data->mut_t));
			pthread_mutex_lock(&(data->mut_print));
			printf("%llu %d died\n", \
			get_time() - data->start_time, data->philos->num);
			return (1);
		}
		pthread_mutex_unlock(&(data->mut_t));
		i++;
	}
	return (0);
}

static int	check_full(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->num_of_ph)
	{
		pthread_mutex_lock(&(data->mut_e));
		if (data->philos[i].eat_count >= data->num_of_eat)
			j++;
		pthread_mutex_unlock(&(data->mut_e));
		i++;
	}
	if (data->num_of_ph == j)
	{
		pthread_mutex_lock(&(data->mut_print));
		printf("all philosophers have eat at least %d times", data->num_of_eat);
		return (1);
	}
	return (0);
}

int	check_end(t_data *data)
{
	while (1)
	{
		if (check_death(data) == 1)
			return (1);
		if (data->num_of_eat != -1)
		{
			if (check_full(data) == 1)
				return (1);
		}
		usleep(300);
	}
	return (0);
}
