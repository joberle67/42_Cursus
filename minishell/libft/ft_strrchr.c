/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:22:21 by joberle           #+#    #+#             */
/*   Updated: 2022/02/27 15:22:25 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	int		nb;

	a = -1;
	nb = -1;
	while (s[++a])
		if (s[a] == c)
			nb = a;
	if (s[a] == c)
		nb = a;
	if (nb > -1)
		return (((char *)s) + nb);
	return (NULL);
}
