/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:42:06 by joberle           #+#    #+#             */
/*   Updated: 2022/07/05 12:42:09 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_list *a)
{
	t_element	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = a->first->next;
	a->first->next = tmp;
	ft_printf("sa\n");
}

void	ra(t_list *a)
{
	t_element	*tmp;
	t_element	*yet;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = NULL;
	yet = a->first;
	while (yet->next != NULL)
		yet = yet->next;
	yet->next = tmp;
	ft_printf("ra\n");
}

void	pa(t_list *a, t_list *b)
{
	t_element	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	b->nb_elem--;
	a->nb_elem++;
	ft_printf("pa\n");
}

void	pb(t_list *a, t_list *b)
{
	t_element	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	a->nb_elem--;
	b->nb_elem++;
	ft_printf("pb\n");
}

void	rra(t_list *a)
{
	t_element	*yet;
	t_element	*tmp;

	yet = a->first;
	while (yet->next->next != NULL)
		yet = yet->next;
	tmp = yet->next;
	yet->next = NULL;
	tmp->next = a->first;
	a->first = tmp;
	ft_printf("rra\n");
}
