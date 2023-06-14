/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:39 by joberle           #+#    #+#             */
/*   Updated: 2022/02/22 15:24:50 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	if (size == 0)
		return (ft_strlen(src));
	a = 0;
	while (src[a] && a < size - 1)
	{
		dst[a] = src[a];
		a++;
	}
	if (a < size + 1)
		dst[a] = '\0';
	return (ft_strlen(src));
}
