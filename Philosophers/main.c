/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:03 by joberle           #+#    #+#             */
/*   Updated: 2022/10/17 14:35:32 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	valid_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == 32)
			j++;
		if (argv[i][j] == '-')
		{
			write(2, "Error: input only positive args\n", 32);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_zero(int argc, int *arg)
{
	if (arg[0] == 0)
	{
		free(arg);
		write(2, "Error: at least 1 philo is needed\n", 34);
		return (1);
	}
	else if (arg[1] == 0)
	{
		free(arg);
		write(2, "Error: philosophers died\n", 25);
		return (1);
	}
	if (argc == 6 && arg[4] == 0)
	{
		free(arg);
		write(2, "Philosophers ate 0 times\n", 25);
		return (1);
	}
	return (0);
}

int	parsing_args(int argc, char **argv, int *data)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == 32)
			j++;
		while (argv[i][j] && ft_isdigit(argv[i][j]) == 1)
			j++;
		if (argv[i][j] != 0)
		{
			write(2, "Error: wrong format of args\n", 28);
			return (1);
		}
		data[i - 1] = ft_atoi(argv[i]);
		if (data[i - 1] == -1)
		{
			write(2, "Error: numbers too long\n", 24);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*arg;
	t_data	*all_data;

	if (valid_check(argc, argv) == 1)
		return (1);
	arg = (int *)malloc(sizeof(int) * (argc - 1));
	if (parsing_args(argc, argv, arg) == 1)
	{
		free(arg);
		return (1);
	}
	if (check_zero(argc, arg) == 1)
		return (1);
	all_data = init_data(argc, arg);
	if (all_data == NULL)
		return (1);
	free(arg);
	if (start_treads(all_data) == 0)
		check_end(all_data);
	free_and_destroy(all_data);
	return (0);
}
