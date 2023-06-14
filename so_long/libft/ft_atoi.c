/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvan@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:21:32 by joberle           #+#    #+#             */
/*   Updated: 2022/02/25 09:30:23 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		a;
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	a = 0;
	while (str[a] == '\n' || str[a] == ' ' || str[a] == '\t'
		|| str[a] == '\r' || str[a] == '\v' || str[a] == '\f')
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = (result * 10) + (str[a] - 48);
		a++;
	}
	return (result * sign);
}
