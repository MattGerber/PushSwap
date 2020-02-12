/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:43 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 11:53:00 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ra(t_stack **stack_a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if ((!*stack_a) || (stack_length(stack_a) < 2))
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	first->previous = last;
	if (i)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b, int i)
{
	t_stack	*first;
	t_stack	*last;

	if ((!*stack_b) || (stack_length(stack_b) < 2))
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	first->previous = last;
	if (i)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (i)
		ft_putendl_fd("rr", 1);
}
