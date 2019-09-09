/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2019/09/09 17:06:31 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort_ineffeciently(t_stack **lista,t_stack **listb)
{
	int i = 1;
	// print_stack(lista);
	// ft_putchar('\n');
	while ((*lista))
	{
		if ((*lista)->weight == i)
		{
			i++;
			pb(lista, listb, 1);
		}
		else
		{
			ra(lista, 1);
		}
	}
	// write(1,"f", 1);
	while ((*listb))
	{
		pa(listb, lista, 1);
	}
	// ft_putchar('\n')	
		//print_stack((*listb));	
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
	
	while(!is_sorted((*lista), (*listb)))
	{
		
		if((*lista)->value < (*lista)->next->value)
			sa(lista, 1);
		else
			ra(lista, 1);
	}
}