/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:33:14 by theDude           #+#    #+#             */
/*   Updated: 2020/02/12 12:36:25 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		find_biggest(t_stack *stacka)
{
	t_stack *bigstack;
	t_stack *current;

	current = stacka;
	bigstack = stacka;
	while (current)
	{
		if (current->weight > bigstack->weight)
			bigstack = current;
		current = current->next;
	}
	return (bigstack->weight);
}

int		find_smallest(t_stack *stacka)
{
	t_stack *smallstack;
	t_stack *current;

	current = stacka;
	smallstack = stacka;
	while (current)
	{
		if (current->weight < smallstack->weight)
			smallstack = current;
		current = current->next;
	}
	return (smallstack->weight);
}

int		push_biggest(t_stack *stacka)
{
	int		bigi;
	int		i;
	t_stack *bigstack;
	t_stack *current;

	current = stacka;
	bigstack = stacka;
	bigi = 0;
	i = 0;
	while (current)
	{
		if (current->weight > bigstack->weight)
		{
			bigstack = current;
			bigi = i;
		}
		current = current->next;
		i++;
	}
	return (bigi);
}

int		push_smallest(t_stack *stacka)
{
	int		smalli;
	int		i;
	t_stack *smallstack;
	t_stack *current;

	current = stacka;
	smallstack = stacka;
	smalli = 0;
	i = 0;
	while (current)
	{
		if (current->weight < smallstack->weight)
		{
			smallstack = current;
			smalli = i;
		}
		current = current->next;
		i++;
	}
	return (smalli + 1);
}

void	algo_pushback(t_stack **stacka, t_stack **stackb)
{
	int i;

	i = 0;
	if ((*stackb)->weight > (stack_length(stackb) / 2))
		i = 1;
	while ((*stackb)->weight != stack_length(stackb))
	{
		if (i)
			rrb(stackb, 1);
		else
			rb(stackb, 1);
	}
	while (*stackb)
	{
		pa(stacka, stackb, 1);
	}
}
