/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:02 by magerber          #+#    #+#             */
/*   Updated: 2019/08/29 10:38:42 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	pb(t_stack *lista, t_stack *listb)
// {
// 	if (lista)
// 	{
// 		//if (lista->head == 1)
// 		//	lista = lista->next;
// 		lista->next->previous = NULL;
// 		listb->previous = lista;
// 		lista->next = listb;
// 		lista->previous = NULL;
// 	}
// }

void pb(t_stack **lista, t_stack **listb)
{
	// printf("%s\n","Nanananana");
	// printf("%p\n", (*listb));
	if	((*listb) == NULL)
	{
		printf("%s\n\n", "nanannananananan");
		(*listb) = (*lista);
		printf(" *lst->b : [%d]\n", (*listb)->value);
		(*lista) =	(*lista)->next;
		(*lista)->previous = NULL;
		(*listb)->next->previous = NULL;
		(*listb)->next = NULL;
	}
	else
	{
		(*listb)->previous = (*lista);
		(*lista) = (*lista)->next;
		(*lista)->previous->next = (*listb);
		(*listb) = (*listb)->previous;
		(*listb)->previous = NULL;
	}
;
	
}

void	pa(t_stack *listb, t_stack *lista)
{
	if (listb)
	{
		//if (lista->head == 1)
	//		listb = listb->next;
		listb->next->previous = NULL;
		lista->previous = listb;
		listb->next = lista;
		listb->previous = NULL;
	}
}

// void	pa(t_stack *listb, t_stack *lista)
// {
// 	if (!lista)
// 	{
// 		listb->next->pre	
// 	}
// }