/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainee.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:38:15 by joberle           #+#    #+#             */
/*   Updated: 2022/07/05 12:38:17 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sup_all_list(t_list *list)
{
	t_element	*to_del;

	if (list == NULL)
		return (2);
	to_del = list->first;
	while (list->first != NULL)
	{
		list->first = list->first->next;
		free(to_del);
		to_del = list->first;
	}
	free(list);
	list = NULL;
	return (0);
}

int	print_list(t_list *list)
{
	t_element	*yet;

	if (list == NULL)
		return (1);
	yet = list->first;
	while (yet != NULL)
	{
		ft_putnbr_fd(yet->nbr, 1);
		ft_putstr_fd(" (", 1);
		ft_putnbr_fd(yet->pos, 1);
		ft_putstr_fd(") ", 1);
		ft_putstr_fd(" -> ", 1);
		yet = yet->next;
	}
	ft_putstr_fd("NULL\n", 1);
	return (0);
}

t_list	*copy_list(t_list *a)
{
	t_list		*copy;
	t_element	*to_cpy;
	t_element	*index;

	if (a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	copy = initialization(a->first->nbr);
	index = copy->first;
	to_cpy = a->first->next;
	while (to_cpy != NULL)
	{
		mid_insertion(copy, index, to_cpy->nbr);
		index = index->next;
		to_cpy = to_cpy->next;
	}
	copy->nb_elem = a->nb_elem;
	return (copy);
}
