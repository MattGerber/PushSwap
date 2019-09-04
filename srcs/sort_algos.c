/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:45:26 by magerber          #+#    #+#             */
/*   Updated: 2019/09/04 13:15:00 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_ineffeciently(t_stack *lista,t_stack *listb)
{
	int i = 1;
	// print_stack(lista);
	// ft_putchar('\n');
	while (lista)
	{
		if (lista->weight == i)
		{
			i++;
			pb(&lista, &listb, 1);
		}
		else
		{
			ra(&lista, 1);
		}
	}
	while (listb)
	{
		pa(&lista, &listb, 1);
	}
	// print_stack(lista);
	// ft_putchar('\n')	
	
}