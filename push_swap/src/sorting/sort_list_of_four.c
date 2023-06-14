/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:42:46 by joberle           #+#    #+#             */
/*   Updated: 2022/07/05 12:42:49 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	top_is_second(t_list *a, t_list *b)
{
	pb(a, b);
	sort_list_of_three(a, 0, 2, 3);
	pa(b, a);
	sa(a);
}

void	top_is_third(t_list *a, t_list *b)
{
	sa(a);
	sup_all_list(b);
	sort_list_of_four(a);
}

void	sort_list_of_four(t_list *a)
{
	t_list		*b;

	b = initialization(-1);
	if (a->first->nbr == 0)
	{
		pb(a, b);
		sort_list_of_three(a, 1, 2, 3);
		pa(b, a);
	}
	else if (a->first->nbr == 1)
		top_is_second(a, b);
	else if (a->first->nbr == 2)
		top_is_third(a, b);
	else if (a->first->nbr == 3)
	{
		pb(a, b);
		sort_list_of_three(a, 0, 1, 2);
		pa(b, a);
		ra(a);
	}
	sup_all_list(b);
}
