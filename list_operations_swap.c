/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:00 by magerber          #+#    #+#             */
/*   Updated: 2019/08/29 14:46:18 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **listhead)
{
	t_stack	*nextelem;
	int		temp;

	if ((*listhead) == NULL || stack_length(listhead) == 1)
		return ;
	nextelem = (*listhead)->next;
	temp = (*listhead)->value;
	(*listhead)->value = nextelem->value;
	nextelem->value = temp;
}

void	sb(t_stack **listhead)
{
	t_stack	*nextelem;
	int		temp;

	if ((*listhead) == NULL || stack_length(listhead) == 1)
		return ;
	nextelem = (*listhead)->next;
	temp = (*listhead)->value;
	(*listhead)->value = nextelem->value;
	nextelem->value = temp;
}

void	ss(t_stack **listheada, t_stack **listheadb)
{
	sa(listheada);
	sb(listheadb);
}
