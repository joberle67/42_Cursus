/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:30:09 by joberle           #+#    #+#             */
/*   Updated: 2022/02/24 14:30:22 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!s2[a])
		return ((char *)s1);
	while (s1[a] && a < len)
	{
		b = 0;
		while (s2[b] && s1[a + b] && s1[a + b] == s2[b]
			&& (a + b) < len)
			b++;
		if (!s2[b])
			return ((char *)s1 + a);
		a++;
	}
	return (NULL);
}
