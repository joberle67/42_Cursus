/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:47:59 by joberle           #+#    #+#             */
/*   Updated: 2022/03/18 13:56:16 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_printnbr(int n)
{
	int		len;
	char	*str;

	str = ft2_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
