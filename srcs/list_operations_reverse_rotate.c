/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:06 by magerber          #+#    #+#             */
/*   Updated: 2019/09/16 16:35:55 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rra(t_stack **stacka, int i)
{
{
	t_stack	*starta;
	t_stack	*first;
	t_stack	*last;

	starta = *stacka;
	first = starta->next;
	last = first->next;
	if (first != NULL && last != NULL)
	{
		while (last->next)
			last = last->next;
		starta->next = last;
		last->previous->next = NULL;
		last->previous = starta;
		last->next = first;
		first->previous = last;
	}
}
	if (i == 1)
		ft_putendl("rra");
}
void	rrb(t_stack **stackb, int i)
{
	t_stack	*startb;
	t_stack	*first;
	t_stack	*last;

	startb = *stackb;
	first = startb->next;
	last = (*stackb)->next->next;
	if (first != NULL && last != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		startb->next = last;
		last->previous->next = NULL;
		last->previous = startb;
		last->next = first;
		first->previous = last;
	}
	if (i == 1)
		ft_putendl("rrb");
}


void	rrr(t_stack **stacka, t_stack **stackb, int i)
{
	rra(stacka, 0);
	rrb(stackb, 0);
	if (i == 1)
		ft_putendl("rrr");
}
