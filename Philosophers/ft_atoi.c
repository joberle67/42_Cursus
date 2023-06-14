/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:03:57 by joberle           #+#    #+#             */
/*   Updated: 2022/10/11 14:03:59 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	figure(const char *str, int start, int end)
{
	int	res;

	res = 0;
	while (end >= start)
	{
		res *= 10;
		res += (str[start] - '0');
		start++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	a;

	res = 0;
	i = 0;
	while (str[i] && (str[i] == 32 || str[i] == 48))
		i++;
	a = i;
	while (str[i])
		i++;
	if ((i - a) > 10)
		return (-1);
	res = figure(str, a, i - 1);
	return (res);
}
