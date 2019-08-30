/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:02 by magerber          #+#    #+#             */
/*   Updated: 2019/08/29 14:18:55 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **lista, t_stack **listb)
{
	if ((*lista) == NULL)
		return ;
	if	((*listb) == NULL)
	{
		(*listb) = (*lista);
		(*lista) =	(*lista)->next;
		(*lista)->previous = NULL;
		(*listb)->next->previous = NULL;
		(*listb)->next = NULL;
	}
	else if ((*lista)->next == NULL)
	{
		(*lista)->next = (*listb);
		(*listb) = (*lista);
		(*lista) = NULL;
	}
	else
	{
 		(*listb)->previous = (*lista);
		(*lista) = (*lista)->next;
		(*lista)->previous->next = (*listb);
		(*listb) = (*listb)->previous;
		(*listb)->previous = NULL;
	}
}

void	pa(t_stack **listb, t_stack **lista)
{
	if ((*listb) == NULL)
		return ;
	if	((*lista) == NULL)
	{
		(*lista) = (*listb);
		(*listb) =	(*listb)->next;
		(*listb)->previous = NULL;
		(*lista)->next->previous = NULL;
		(*lista)->next = NULL;
	}
	else if ((*listb)->next == NULL)
	{
		(*listb)->next = (*lista);
		(*lista) = (*listb);
		(*listb) = NULL;
	}
	else
	{
 		(*lista)->previous = (*listb);
		(*listb) = (*listb)->next;
		(*listb)->previous->next = (*lista);
		(*lista) = (*lista)->previous;
		(*lista)->previous = NULL;
	}
}
