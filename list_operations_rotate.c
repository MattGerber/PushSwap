/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:43 by magerber          #+#    #+#             */
/*   Updated: 2019/08/23 11:34:24 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stacka)
{
	t_stack	*head;
	t_stack *last;

	head = stacka;
	last = stacka;
	while (last->next != NULL)
		last = last->next;
	stacka = head->next;
	stacka->previous = NULL;
	last->next = head;
	head->next = NULL;
	head->previous = last;
}

void	rb(t_stack *stackb)
{
	t_stack	*head;
	t_stack *last;

	head = stackb;
	last = stackb;
	while (last->next != NULL)
		last = last->next;
	stackb = head->next;
	stackb->previous = NULL;
	last->next = head;
	head->next = NULL;
	head->previous = last;
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	ra(stacka);
	rb(stackb);
}
