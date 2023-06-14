/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:45:55 by joberle           #+#    #+#             */
/*   Updated: 2022/03/18 13:54:31 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_pourcent(va_list args, const char c)
{
	int	nb;

	nb = 0;
	if (c == 'c')
		nb += ft_putchar(va_arg(args, int));
	else if (c == 's')
				nb += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
				nb += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
				nb += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
				nb += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
				nb += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
				nb += ft_putchar('%');
	return (nb);
}
