/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:02 by magerber          #+#    #+#             */
/*   Updated: 2019/08/23 11:33:39 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *lista, t_stack *listb)
{
	lista->next->previous = NULL;
	listb->previous = lista;
	lista->next = listb;
	lista->previous = NULL;
}

void	pa(t_stack *listb, t_stack *lista)
{
	listb->next->previous = NULL;
	lista->previous = listb;
	listb->next = lista;
	listb->previous = NULL;
}
