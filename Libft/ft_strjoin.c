/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:02 by joberle           #+#    #+#             */
/*   Updated: 2022/02/25 15:39:26 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	c = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		str[c] = s1[a];
		a++;
		c++;
	}
	b = 0;
	while (s2[b])
	{
		str[c] = s2[b];
		b++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
