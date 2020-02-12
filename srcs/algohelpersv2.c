/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algohelpersv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:39:39 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 17:59:57 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort_five(t_stack *stacka, t_stack *stackb)
{
	while (stack_length(&stackb) < 3)
	{
		if (stacka->weight == 5 || stacka->weight == 4)
			ra(&stacka, 1);
		else
			pb(&stacka, &stackb, 1);
	}
	while (!sorted(stackb))
	{
		if (stackb->value < stackb->next->next->value)
			rb(&stackb, 1);
		else
			sb(&stackb, 1);
	}
	while (stackb)
		pa(&stacka, &stackb, 1);
}

void	execute_both(t_bestmove *move, t_stack **stacka, t_stack **stackb)
{
	while (move->a_move != 0 && move->b_move != 0)
	{
		if (move->a_move < 0 && move->b_move < 0)
		{
			rrr(stacka, stackb, 1);
			move->a_move++;
			move->b_move++;
		}
		else
		{
			rr(stacka, stackb, 1);
			move->a_move--;
			move->b_move--;
		}
	}
}

void	initialise_struct(t_bestmove *best, t_bestmove *current)
{
	best->a_move = 0;
	best->b_move = 0;
	best->total = -1;
	current->a_move = 0;
	current->b_move = 0;
	current->total = 0;
}

void	set_move(t_stack *stackb, t_stack *a, t_bestmove *current)
{
	current->b_move = calculate_bmove(stackb, a->weight);
	if (current->a_move < 0 && current->b_move < 0)
		current->total = (current->a_move < current->b_move) ?
			current->a_move : current->b_move;
	else if (current->a_move > 0 && current->b_move > 0)
		current->total = (current->a_move < current->b_move) ?
			current->b_move : current->a_move;
	else if (current->a_move < 0 || current->b_move < 0)
		current->total = (current->a_move < 0) ?
		((current->a_move * -1) + current->b_move)
		: (current->a_move + (current->b_move * -1));
	else
		current->total = (current->a_move + current->b_move);
	current->total = (current->total < 0) ?
	current->total * -1 : current->total;
}
