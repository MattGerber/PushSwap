/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:02 by magerber          #+#    #+#             */
/*   Updated: 2020/01/14 14:56:42 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int p_bool)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	if (stack_b != NULL)
	{
		tmp = *stack_b;
		if ((*stack_b)->next)
			*stack_b = (*stack_b)->next;
		else
			*stack_b = NULL;
		if (*stack_b)
			(*stack_b)->previous= NULL;
		if (stack_a == NULL)
			stack_add_head(stack_a, tmp);
		else if (stack_a != NULL)
			stack_add_head(stack_a, tmp);
		if (p_bool)
			ft_putendl_fd("pa", 1);
	}
}

/*
** pb: push b - take the first element at the top of a and put it at the top of
** b. Do nothing if a is empty.
*/

void	pb(t_stack **stack_a, t_stack **stack_b, int p_bool)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	if (stack_a != NULL)
	{
		tmp = *stack_a;
		if ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		else
			*stack_a = NULL;
		if (*stack_a)
			(*stack_a)->previous= NULL;
		if (stack_b == NULL)
			stack_add_head(stack_b, tmp);
		else if (stack_b != NULL)
			stack_add_head(stack_b, tmp);
		if (p_bool)
			ft_putendl_fd("pb", 1);
	}
}