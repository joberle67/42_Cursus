/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:48:31 by joberle           #+#    #+#             */
/*   Updated: 2022/03/18 14:20:44 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa2(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n)
	{
		num[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length = ft_putchar('0');
	else
	{
		num = ft_itoa2(n);
		print_length = ft_printstr(num);
		free(num);
	}
	return (print_length);
}	
