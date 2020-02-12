/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:00 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 12:00:43 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sa(t_stack **stack_a, int i)
{
	t_stack		*temp;
	t_stack		*next_temp;

	if (!*stack_a)
		return ;
	if ((*stack_a)->next != NULL)
	{
		temp = *stack_a;
		next_temp = (*stack_a)->next;
		temp->previous = next_temp;
		temp->next = next_temp->next;
		next_temp->previous = NULL;
		next_temp->next = temp;
		*stack_a = next_temp;
		if (i)
			ft_putendl_fd("sa", 1);
	}
}

void	sb(t_stack **stack_b, int i)
{
	t_stack		*temp;
	t_stack		*next_temp;

	if (!*stack_b)
		return ;
	if ((*stack_b)->next != NULL)
	{
		temp = *stack_b;
		next_temp = (*stack_b)->next;
		temp->previous = next_temp;
		temp->next = next_temp->next;
		next_temp->previous = NULL;
		next_temp->next = temp;
		*stack_b = next_temp;
		if (i)
			ft_putendl_fd("sb", 1);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (i)
		ft_putendl_fd("ss", 1);
}
