/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:43:13 by joberle           #+#    #+#             */
/*   Updated: 2022/07/05 12:43:15 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small_stack(t_list *a)
{
	sort_list(a);
	if (a->nb_elem == 2)
		sa(a);
	else if (a->nb_elem == 3)
		sort_list_of_three(a, 0, 1, 2);
	else if (a->nb_elem == 4)
		sort_list_of_four(a);
	else if (a->nb_elem == 5)
		sort_list_of_five(a);
}
