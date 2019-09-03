/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:43 by magerber          #+#    #+#             */
/*   Updated: 2019/09/03 14:03:33 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stacka)
{
	t_stack	*head;
	t_stack *last;

	if ((*stacka) != NULL)
	{
		if ((*stacka)->next != NULL)
		{
			head = (*stacka);
			last = (*stacka);
			while (last->next != NULL)
				last = last->next;
			(*stacka) = head->next;
			(*stacka)->previous = NULL;
			last->next = head;
			head->next = NULL;
			head->previous = last;
		}
	}
}

void	rb(t_stack **stackb)
{
	t_stack	*head;
	t_stack *last;
	
	if ((*stackb) != NULL)
	{
		if ((*stackb)->next != NULL)
		{
			head = (*stackb);
			last = (*stackb);
			while (last->next != NULL)
				last = last->next;
			(*stackb) = head->next;
			(*stackb)->previous = NULL;
			last->next = head;
			head->next = NULL;
			head->previous = last;
		}
	}
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
 	rb(stackb);
}
