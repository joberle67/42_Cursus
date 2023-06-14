/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:45:34 by joberle           #+#    #+#             */
/*   Updated: 2022/03/18 13:51:31 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int nb, const char c)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, c);
		ft_put_hex(nb % 16, c);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (c == 'x')
				ft_putchar(nb + 87);
			if (c == 'X')
				ft_putchar(nb + 55);
		}
	}
}

int	ft_printhex(unsigned int nb, const char c)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_put_hex(nb, c);
	return (ft_hexlen(nb));
}
