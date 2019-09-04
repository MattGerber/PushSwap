/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:06 by magerber          #+#    #+#             */
/*   Updated: 2019/09/04 13:07:14 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stacka, int i)
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
	if (i == 1)
		ft_putendl("rra");
}
void	rrb(t_stack **stackb, int i)
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
