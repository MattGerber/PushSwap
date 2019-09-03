/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:06 by magerber          #+#    #+#             */
/*   Updated: 2019/09/03 14:03:29 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stacka)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((!*stacka) || (stack_length(stacka) < 2))
		return ;
	last = *stacka;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *stacka;
	*stacka = last;
}
void	rrb(t_stack **stackb)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((!*stackb) || (stack_length(stackb) < 2))
		return ;
	last = *stackb;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *stackb;
	*stackb = last;
}


void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
}
