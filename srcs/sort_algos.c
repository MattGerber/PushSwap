/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2020/02/06 10:31:31 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		execute_move(t_stack **list, int i, char c)
{
	while(i != 0)
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
	return(i);
}

void	sort_three_asc(t_stack **lista,t_stack **listb)
{
	while(!is_sorted_asc((*lista), (*listb)))
	{
		if((*lista)->value > (*lista)->next->next->value)
			ra(lista, 1);
		else 
			sa(lista, 1);
	}	
}

void	sort_three_des(t_stack **lista,t_stack **listb)
{
	while(!is_sorted_des((*lista), (*listb)))
	{
		if((*lista)->value < (*lista)->next->next->value)
			ra(lista, 1);
		else 
			sa(lista, 1);
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
	best->a_move = 0;
	best->b_move = 0;
	best->total = -1;
	current->a_move = 0;
	current->b_move = 0;
	current->total = 0;
	i = 0;
	a = stacka;
	while (a)
	{
		if (i > (stack_length(&stacka) / 2)){
			i = (i - stack_length(&stacka));
		}
		current->a_move = i;
		current->b_move = calculate_bmove(stackb, a->weight);
		if (current->a_move < 0 && current->b_move < 0)
			current->total = (current->a_move < current->b_move) ? current->a_move : current->b_move;
		else if  (current->a_move > 0 && current->b_move > 0)
			current->total = (current->a_move < current->b_move) ? current->b_move : current->a_move;
		else if (current->a_move < 0 || current->b_move < 0)
			current->total = (current->a_move < 0)? ((current->a_move * -1) + current->b_move) : (current->a_move + (current->b_move * -1));
		else
			current->total = (current->a_move + current->b_move);
		current->total = (current->total < 0) ? current->total * -1 : current->total;
		if (current->total < best->total || best->total == -1)
		{
			best->a_move = current->a_move;
			best->b_move = current->b_move;
			best->total = current->total;
		}
		a = a->next;
		i++;
	}
	return(best);
}

void		sort_stack(t_stack **stacka, t_stack **stackb)
{
	int	i;
	t_bestmove	*move;
	
	move = (t_bestmove *)malloc(sizeof(t_bestmove));
	pb(stacka, stackb, 1);
	pb(stacka, stackb, 1);
	pb(stacka, stackb, 1);
	while(!sorted((*stackb)))
	{
		if((*stackb)->value < (*stackb)->next->next->value)
			rb(stackb, 1);
		else 
			sb(stackb, 1);
	}	
	while (*stacka)
	{
		move = bestmove(*stacka, *stackb);
		if ((move->a_move < 0 && move->b_move < 0) || (move->a_move > 0 && move->b_move > 0))
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

			if (execute_move(stacka, move->a_move, 'a') == 0 &&	execute_move(stackb, move->b_move, 'b') == 0)
				pb(stacka, stackb, 1);
	}

	while ((*stackb)->weight != stack_length(stackb))
	{
		rb(stackb, 1);
	}	
	while (*stackb)
	{
		pa(stacka, stackb, 1);
	}
	
}

int		findnum_move(t_stack *stackb, int numweight)
{
	int i;
	t_stack *current;

	i = 0;
	current = stackb;
	while (current->weight != numweight)
	{
		i++;
		current = current->next;
	}
	return(i);
}

int		calculate_bmove(t_stack *stackb, int numweight)
{
	t_stack *smallstack;
	t_stack *current;
	t_stack *after;
	int 	i;
	int		move;
	i = 0;

	current = stackb;
	after = stackb->next;
	smallstack = stackb;

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
		while (current)
		{
			if (current->weight > numweight && after->weight < numweight)
			{
		
				if (after->weight > current->weight)
					smallstack = current;
				else
					smallstack = after;
			
			}
			current = current->next;
			i++;
			if (current)
			{
				if (current->next == NULL)
					after = stackb;
				else
					after= current->next;
			}
		}
		move = findnum_move(stackb, smallstack->weight);
	}
		if (move > (stack_length(&stackb) / 2))
		{
			move = move - stack_length(&stackb);
		}
	return(move);
}

int		find_biggest(t_stack *stacka){

	t_stack *bigstack;
	t_stack *current;

	current = stacka;
	bigstack = stacka;
	while (current) {
		if (current->weight > bigstack->weight)
			bigstack = current;
		current = current->next;
	}
	return(bigstack->weight);
}

int		find_smallest(t_stack *stacka)
{
	t_stack *smallstack;
	t_stack *current;

	current = stacka;
	smallstack = stacka;
	while (current) {
		if (current->weight < smallstack->weight)
			smallstack = current;
		current = current->next;
	}
	return(smallstack->weight);
}

int		push_biggest(t_stack *stacka)
{
	int bigi;
	int i;
	t_stack *bigstack;
	t_stack *current;

	current = stacka;
	bigstack = stacka;
	bigi = 0;
	i = 0;
	while (current) {
		if (current->weight > bigstack->weight){
			bigstack = current;
			bigi = i;
		}
		current = current->next;
		i++;
	}
	return(bigi);
}

int		push_smallest(t_stack *stacka)
{
	int smalli;
	int i;
	t_stack *smallstack;
	t_stack *current;

	current = stacka;
	smallstack = stacka;
	smalli = 0;
	i = 0;
	while (current) {
		if (current->weight < smallstack->weight){
			smallstack = current;
			smalli = i;
		}
		current = current->next;
		i++;
	}
	return(smalli + 1);
}