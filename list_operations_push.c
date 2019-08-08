/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:02 by magerber          #+#    #+#             */
/*   Updated: 2019/08/08 11:05:02 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *lista, t_stack *listb)
{
	if (listb == NULL)
	{
		lista->next->previous = NULL;
		lista->next = NULL;
		lista->previous = NULL;
		listb = lista;
	}
	else
	{
		lista->next->previous = NULL;
		listb->previous = lista;
		lista->next = listb;
		lista->previous = NULL;
	}	
}

void	pa(t_stack *listb, t_stack *lista)
{
	listb->next->previous = NULL;
	lista->previous = listb;
	listb->next = lista;
	listb->previous = NULL;	
}