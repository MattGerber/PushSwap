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

int		execute_move(t_stack **list, int i)
{
	while(i != 0)
	{
		if (i < 0)
		{
			rra(list, 1);
			i++;
		}
		else
		{
			ra(list, 1);
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
			i = (i- stack_length(&stacka));
		}
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
			best = current;
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
	execute_move(stacka, push_biggest(*stacka));
	pb(stacka, stackb, 1);
	pb(stacka, stackb, 1);
	execute_move(stacka, push_smallest(*stacka));
	pb(stacka, stackb, 1);
	while(!sorted((*stackb)))
	{
		if((*stackb)->value < (*stackb)->next->next->value)
			rb(stackb, 1);
		else 
			sb(stackb, 1);
	}	
	print_stack(*stackb);


	// move = bestmove(*stacka, *stackb);
	while (*stacka)
	{
		move = bestmove(*stacka, *stackb);
		ft_putstr("a = ");
		ft_putnbr(move->a_move);
		ft_putchar('\n');
				ft_putstr("b = ");
		ft_putnbr(move->b_move);
		ft_putchar('\n');
				ft_putstr("t = ");
		ft_putnbr(move->total);
		ft_putchar('\n');
		
		// printf("a = %d \n b = %d \n t = %d", move->a_move, move->b_move, move->total);
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

			if (execute_move(stacka, move->a_move) == 0 &&	execute_move(stackb, move->b_move) == 0)
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

int		calculate_bmove(t_stack *stackb, int numweight)
{
	int		move;
	int 	i;
	t_stack *smallstack;
	t_stack *current;
	move = 0;
	current = stackb;
	smallstack = stackb;
	i = 0;
	while (current)
	{
		if (current->weight > numweight && smallstack->weight > current->weight)
		{
			smallstack = current;
			move = i + 1;
		}
		current = current->next;
		i++;
	}
		if (move > (i / 2))
		{
			move = (move - i);
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
	if (bigi > (i / 2)){
		bigi = (bigi - i);
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
	if (smalli > (i / 2)){
		smalli = (smalli - i);
	}
	return(smalli);
}