/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:44:45 by joberle           #+#    #+#             */
/*   Updated: 2022/07/06 12:28:47 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == (int)ft_strlen(str))
		exit (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;

	if (ac < 2)
		return (0);
	if (ac == 2 && is_space(av[1]))
		a = convert_single_string(av[1]);
	else
		a = parsing(0, ac, av, -1);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (a_is_sorted(a) < 0)
	{
		sup_all_list(a);
		return (0);
	}
	if (a->nb_elem <= 5)
		sort_small_stack(a);
	else
		sort_big_stack(a);
	sup_all_list(a);
	return (0);
}
