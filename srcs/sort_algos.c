/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2019/09/12 12:44:02 by magerber         ###   ########.fr       */
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
	// write(1,"f", 1);
	// while ((*listb))
	// {
		// pb(listb, lista, 1);
	// }
	// ft_putchar('\n')	
		//print_stack((*listb));	
		// print_stack((*lista));
		//print_stack((*lista));
}

void	sort_three(t_stack **lista,t_stack **listb)
{
	while(!is_sorted((*lista), (*listb)))
	{
		if((*lista)->value > (*lista)->next->next->value)
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
	while(!is_sorted((*lista), (*listb)))
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