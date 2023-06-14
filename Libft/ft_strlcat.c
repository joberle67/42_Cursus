/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:27:01 by joberle           #+#    #+#             */
/*   Updated: 2022/02/23 19:27:26 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total;
	size_t	original;

	original = size;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + original);
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = 0;
	return (total);
}
