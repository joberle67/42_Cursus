/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:43:27 by joberle           #+#    #+#             */
/*   Updated: 2022/07/06 13:01:03 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb_zero(t_list *a, t_list *b)
{
	if (a->first->nbr == 0)
		pb(a, b);
	else if (a->first->next->nbr == 0)
	{
		sa(a);
		pb(a, b);
	}
	else if (a->first->next->next->nbr == 0)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->nbr == 0)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->next->nbr == 0)
	{
		rra(a);
		pb(a, b);
	}
}

void	pb_one(t_list *a, t_list *b)
{
	if (a->first->nbr == 1)
		pb(a, b);
	else if (a->first->next->nbr == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (a->first->next->next->nbr == 1)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->nbr)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort_list_of_five(t_list *a)
{
	t_list	*b;
	int		nb;

	nb = 0;
	b = initialization(-1);
	pb_zero(a, b);
	if (!a_is_sorted(a))
	{
		pb_one(a, b);
		nb++;
	}
	if (!a_is_sorted(a))
		sort_list_of_three(a, 2, 3, 4);
	pa(b, a);
	if (nb > 0)
		pa(b, a);
	sup_all_list(b);
}
