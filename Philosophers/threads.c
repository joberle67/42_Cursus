/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:21 by joberle           #+#    #+#             */
/*   Updated: 2022/10/11 14:04:22 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->num_of_ph);
	while (i < data->num_of_ph)
	{
		philos[i].num = i + 1;
		philos[i].eat_count = 0;
		philos[i].last_meal_time = data->start_time;
		philos[i].right_fork = i + 2;
		philos[i].left_fork = i + 1;
		if (i == data->num_of_ph - 1)
		{
			philos[i].left_fork = 1;
			philos[i].right_fork = i + 1;
		}
		philos[i].info = data;
		i++;
	}
	return (philos);
}

t_data	*init_data(int argc, int *arg)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->num_of_ph = arg[0];
	data->time_d = arg[1];
	data->time_e = arg[2];
	data->time_s = arg[3];
	if (argc == 6)
		data->num_of_eat = arg[4];
	else
		data->num_of_eat = -1;
	data->start_time = get_time();
	data->philos = init_philo(data);
	return (data);
}

int	start_treads(t_data *d)
{
	int	i;

	i = 0;
	d->forks = malloc(sizeof(pthread_mutex_t) * d->num_of_ph);
	if (d->forks == NULL)
	{
		write(2, "Malloc error\n", 13);
		return (1);
	}
	while (i < d->num_of_ph)
		pthread_mutex_init(&(d->forks[i++]), NULL);
	pthread_mutex_init(&(d->mut_print), NULL);
	pthread_mutex_init(&(d->mut_e), NULL);
	pthread_mutex_init(&(d->mut_t), NULL);
	d->threads = malloc(sizeof(pthread_t) * d->num_of_ph);
	i = -1;
	while (++i < d->num_of_ph)
	{
		if (pthread_create(&(d->threads[i]), NULL, ph_rutin, &(d->philos[i])))
			return (1);
	}
	i = 0;
	while (i < d->num_of_ph)
		pthread_detach(d->threads[i++]);
	return (0);
}

static void	eat_philo(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->forks[ph->right_fork - 1]));
	print(ph, "has taken a fork");
	pthread_mutex_lock(&(ph->info->forks[ph->left_fork - 1]));
	print(ph, "has taken a fork");
	pthread_mutex_lock(&(ph->info->mut_t));
	ph->last_meal_time = get_time();
	pthread_mutex_unlock(&(ph->info->mut_t));
	print(ph, "is eating");
	my_usleep(ph->info->time_e);
	pthread_mutex_unlock(&(ph->info->forks[ph->left_fork - 1]));
	pthread_mutex_unlock(&(ph->info->forks[ph->right_fork - 1]));
	pthread_mutex_lock(&(ph->info->mut_e));
	ph->eat_count++;
	pthread_mutex_unlock(&(ph->info->mut_e));
}

void	*ph_rutin(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->num % 2 == 0)
		usleep(700);
	while (1)
	{
		eat_philo(ph);
		print(ph, "is sleeping");
		my_usleep(ph->info->time_s);
		print(ph, "is thinking");
		usleep(300);
	}
}
