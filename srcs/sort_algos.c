/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 17:59:52 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int			execute_move(t_stack **list, int i, char c)
{
	while (i != 0)
	{
		if (i < 0)
		{
			if (c == 'a')
				rra(list, 1);
			else
				rrb(list, 1);
			i++;
		}
		else
		{
			if (c == 'a')
				ra(list, 1);
			else
				rb(list, 1);
			i--;
		}
	}
	return (i);
}

void		set_best(t_bestmove *best, t_bestmove *current)
{
	if (current->total < best->total || best->total == -1)
	{
		best->a_move = current->a_move;
		best->b_move = current->b_move;
		best->total = current->total;
	}
}

t_bestmove	*bestmove(t_stack *stacka, t_stack *stackb)
{
	t_bestmove	*best;
	t_bestmove	*current;
	t_stack		*a;
	int			i;

	best = (t_bestmove *)malloc(sizeof(t_bestmove));
	current = (t_bestmove *)malloc(sizeof(t_bestmove));
	i = 0;
	a = stacka;
	initialise_struct(best, current);
	while (a)
	{
		if (i > (stack_length(&stacka) / 2))
			i = (i - stack_length(&stacka));
		current->a_move = i;
		set_move(stackb, a, current);
		set_best(best, current);
		a = a->next;
		i++;
	}
	free(current);
	return (best);
}

void		start_algo(t_stack **stacka, t_stack **stackb)
{
	pb(stacka, stackb, 1);
	pb(stacka, stackb, 1);
	pb(stacka, stackb, 1);
	while (!sorted((*stackb)))
	{
		if ((*stackb)->value < (*stackb)->next->next->value)
			rb(stackb, 1);
		else
			sb(stackb, 1);
	}
}

void		sort_stack(t_stack **stacka, t_stack **stackb)
{
	int			i;
	t_bestmove	*move;

	start_algo(stacka, stackb);
	while (*stacka)
	{
		move = bestmove(*stacka, *stackb);
		if ((move->a_move < 0 && move->b_move < 0)
			|| (move->a_move > 0 && move->b_move > 0))
		{
			execute_both(move, stacka, stackb);
		}
		if ((execute_move(stacka, move->a_move, 'a') == 0)
			&& (execute_move(stackb, move->b_move, 'b') == 0))
		{
			pb(stacka, stackb, 1);
		}
		free(move);
	}
	algo_pushback(stacka, stackb);
}
