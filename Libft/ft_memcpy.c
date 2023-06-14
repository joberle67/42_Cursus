/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:48:48 by joberle           #+#    #+#             */
/*   Updated: 2022/02/24 12:49:09 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	if (!dst && !src)
		return (0);
	a = 0;
	while (a < n)
	{
		((char *)dst)[a] = ((char *)src)[a];
		a++;
	}
	return (dst);
}
