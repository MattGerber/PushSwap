/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2020/01/14 15:03:46 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort_ineffeciently(t_stack **lista,t_stack **listb, int start, int end)
{
	int i = start;
	// print_stack(lista);
	// ft_putchar('\n');
	while (i <= end)
	{
		if ((*listb)->weight == end)
		{
			i++;
			pa(lista, listb, 1);
		}
		else
		{
			rb(listb, 1);
		}
	}
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

void	sort_V2(t_stack **lista,t_stack **listb)
{
	int		start;
	int		end;
	int		i;

	i = 1;
	start = 1;
	end = 20;	
	while(!is_sorted_asc((*lista), (*listb)))
	{
		while (i <= end)
		{
			if((*lista)->weight <= end & (*lista)->weight >= start)
			{
				pb(lista, listb, 1);
				i++;
			}
			else
			{
				ra(lista, 0);
			}
			
		}
		sort_ineffeciently(lista, listb, start, end);
		start += 20;
		end += 20;
		if (end > 100)
			end = 100;
	}
}

void	sort_stack(t_stack **stacka, t_stack **stackb)
{
	int i;

	while(*stacka){	
		i = push_smallest(*stacka);
		while(i != 0){
			if(i < 0){
				rra(stacka, 1);
				i++;
			}else {
				ra(stacka, 1);
				i--;
			}
		}
		if (i == 0)
			pb(stacka, stackb, 1);
	}

		while (*stackb)
		{
			pa(stacka, stackb, 1);
			// printf("%d", (*stacka)->weight);
		}
	
}

int		push_smallest(t_stack *stacka){

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
