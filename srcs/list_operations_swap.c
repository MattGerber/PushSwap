/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:52:00 by magerber          #+#    #+#             */
/*   Updated: 2019/09/09 12:05:33 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sa(t_stack **listhead, int i)
{
	t_stack	*nextelem;
	int		temp;

	if ((*listhead) == NULL || stack_length(listhead) == 1)
		return ;
	nextelem = (*listhead)->next;
	temp = (*listhead)->value;
	(*listhead)->value = nextelem->value;
	nextelem->value = temp;
	if (i == 1)
		ft_putendl("sa");
}

void	sb(t_stack **listhead, int i)
{
	t_stack	*nextelem;
	int		temp;

	if ((*listhead) == NULL || stack_length(listhead) == 1)
		return ;
	nextelem = (*listhead)->next;
	temp = (*listhead)->value;
	(*listhead)->value = nextelem->value;
	nextelem->value = temp;
	if (i == 1)
		ft_putendl("pb");
}

void	ss(t_stack **listheada, t_stack **listheadb, int i)
{
	sa(listheada, 0);
	sb(listheadb, 0);
	if (i == 1)
		ft_putendl("pb");
}
