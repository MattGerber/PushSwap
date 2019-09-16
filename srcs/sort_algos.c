/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2019/09/16 16:19:39 by magerber         ###   ########.fr       */
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
	t_bestmove	currentmove;
	t_bestmove	bestmove;
	t_stack		*start;
	t_stack		*end;
	int			stacksize;

	stacksize = stack_length(stacka);
	while(stacka)
	{
		stacksize = push_smallest((*stacka));
		if(stacksize > 0)
		{
			while (stacksize > 0)
			{
				ra(stacka, 1);
				stacksize--;
				ft_putnbr(stacksize);
			}
		}
		else if (stacksize < 0)
		{
			while (stacksize != 0)
			{
				rra(stacka, 1);
				stacksize++;
				ft_putnbr(stacksize);
			}	
		}
		if (stacksize == 0)
			pb(stacka, stackb, 1);
	}
	while ((*stackb))
	{
		pa(stackb, stacka, 1);
	}
}

int		push_biggest(t_stack *stacka)
{
	int		i;
	int		reti;
	t_stack	*list;
	t_stack	*retnum;

	i = 0;
	list = stacka;
	retnum = stacka;
	reti = 0;
	while(stack_length(&stacka) >= i )
	{
		if (list->weight > retnum->weight)
		{	
			reti = i;
			retnum = list;
		}
		if (list->next)
			list = list->next;
		i++;						
	}
	if (i > (stack_length(&stacka) / 2))
		i = (i - (stack_length(&stacka) / 2) * -1);
	return (i);
}

int		push_smallest(t_stack *stacka)
{
	int		i;
	int		reti;
	int		stacklen;
	t_stack	*list;
	t_stack	*retnum;

	i = 0;
	stacklen = stack_length(&stacka);
	list = stacka;
	retnum = stacka;
	reti = 0;
	while(stacklen >= i )
	{
		if (list->weight < retnum->weight)
		{	
			reti = i;
			retnum = list;
		}
		if (list->next)
			list = list->next;
		i++;						
	}
	if (i > (stacklen / 2))
		i = ((i - (stacklen / 2)) * -1);
	return (i);	
}
