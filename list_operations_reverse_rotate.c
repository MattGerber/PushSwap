/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:06 by magerber          #+#    #+#             */
/*   Updated: 2019/08/29 15:15:58 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacka)
{
	t_stack	*head;
	t_stack *last;

			head = (*stacka);
			last = (*stacka);
			while (last->next != NULL)
				last = last->next;
			last->previous->next = NULL;
			last->previous = NULL;
			last->next = head;
			head->previous = last;
			head = head->previous;

}

void	rrb(t_stack **stackb)
{
	t_stack	*head;
	t_stack *last;

	head = (*stackb);
	last = (*stackb);
	while (last->next != NULL)
		last = last->next;
	head->previous = last;
	last->next = head;
	last->previous->next = NULL;
	last->previous = NULL;
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
}
