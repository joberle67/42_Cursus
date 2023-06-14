/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:48:20 by joberle           #+#    #+#             */
/*   Updated: 2022/03/18 14:00:30 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		a;
	va_list	args;
	int		nb;

	a = 0;
	nb = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str[a] == '%')
		{
			nb += ft_pourcent(args, str[a + 1]);
			a++;
		}
		else
			nb += ft_putchar(str[a]);
		a++;
	}
	va_end(args);
	return (nb);
}
