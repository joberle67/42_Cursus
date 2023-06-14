/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:44:26 by joberle           #+#    #+#             */
/*   Updated: 2022/07/05 13:14:53 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_count_str(char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
		{
			nb++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	return (nb);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_nbr(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			++j;
		while (s[i] && s[i] == c)
			i++;
		i++;
	}
	return (j);
}

t_list	*convert_arg_into_list(int split, int ac, char **av)
{
	t_list	*list;
	int		i;
	int		nbr;
	int		limit;

	if (split == 1)
		limit = 0;
	else
		limit = 1;
	i = ac - 1;
	nbr = ft_atoi(av[i]);
	i--;
	list = initialization(nbr);
	while (limit <= i)
	{
		nbr = ft_atoi(av[i]);
		insertion(list, nbr);
		i--;
	}
	if (split == 1)
		list->nb_elem = ac;
	else
		list->nb_elem = ac - 1;
	return (list);
}

int	scroll_str_and_check_if_digit(int ac, char **av, int i, int j)
{
	while (i < ac && av[i] != NULL)
	{
		if (av[i][j] == '-' && ft_strlen(av[i]) == 1)
			return (-1);
		if (av[i][0] == '-')
			j++;
		while (ft_isdigit(av[i][j]) == 1)
			j++;
		if ((int)ft_strlen(av[i]) == j)
		{
			i++;
			j = 0;
		}
		else
			return (-1);
	}
	return (0);
}
