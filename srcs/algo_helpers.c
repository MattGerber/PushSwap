/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:28:04 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 12:35:25 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort_three_asc(t_stack **lista, t_stack **listb)
{
	while (!is_sorted_asc((*lista), (*listb)))
	{
		if ((*lista)->value > (*lista)->next->next->value)
			ra(lista, 1);
		else
			sa(lista, 1);
	}
}

void	sort_three_des(t_stack **lista, t_stack **listb)
{
	while (!is_sorted_des((*lista), (*listb)))
	{
		if ((*lista)->value < (*lista)->next->next->value)
			ra(lista, 1);
		else
			sa(lista, 1);
	}
}

int		findnum_move(t_stack *stackb, int numweight)
{
	int		i;
	t_stack *current;

	i = 0;
	current = stackb;
	while (current->weight != numweight)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int		find_pos(t_stack *stackb, int numweight)
{
	t_stack *smallstack;
	t_stack *current;
	t_stack *after;
	int		i;

	i = 0;
	current = stackb;
	after = stackb->next;
	smallstack = stackb;
	while (current)
	{
		if (current->weight > numweight && after->weight < numweight)
			smallstack = (after->weight > current->weight) ? current : after;
		current = current->next;
		i++;
		if (current)
			after = (current->next == NULL) ? stackb : current->next;
	}
	return (findnum_move(stackb, smallstack->weight));
}

int		calculate_bmove(t_stack *stackb, int numweight)
{
	int	move;

	if (numweight > find_biggest(stackb))
	{
		move = push_biggest(stackb);
	}
	else if (numweight < find_smallest(stackb))
	{
		move = push_smallest(stackb);
	}
	else
	{
		move = find_pos(stackb, numweight);
	}
	if (move > (stack_length(&stackb) / 2))
	{
		move = move - stack_length(&stackb);
	}
	return (move);
}
