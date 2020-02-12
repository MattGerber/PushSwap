/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:06 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 11:54:21 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rra(t_stack **stack_a, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((!*stack_a) || (stack_length(stack_a) < 2))
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (i)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((!*stack_b) || (stack_length(stack_b) < 2))
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->previous = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (i)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (i)
		ft_putendl_fd("rrr", 1);
}
