/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:57 by magerber          #+#    #+#             */
/*   Updated: 2019/08/08 11:20:00 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_new_node(t_stack *previous, int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	new_stack->next = NULL;
	new_stack->previous = NULL;
	new_stack->value = value;

	if (previous != NULL)
	{
		previous->next = new_stack;
		new_stack->previous = previous;
	}

	return(new_stack);
}

void	clean_stack(t_stack *start)
{
	t_stack	*freeme;
	t_stack *holdme;

	freeme = start;
	holdme = NULL;
	while (freeme->next != NULL)
	{
		holdme = freeme->next;
		free(freeme);
		freeme = holdme;
	}
}

	t_stack *find_list_head(t_stack *node)
{
	if (node != NULL)
	{
		if (node->previous == NULL)
			return (node);
		else

			while (node->previous != NULL )
			{
				node = node->previous;
			}
	}
	return(node);
}

void	print_stack(t_stack	*start)
{
	t_stack	*currentnode;
	int		count;
	
	if (start != NULL)
	{
		count = 0;
		currentnode = start;
		while (currentnode->previous != NULL )
		{
			currentnode = currentnode->previous;
		}
		while (currentnode)
		{
			count++;
			printf("item %d = %d\n", count, currentnode->value);
			currentnode = currentnode->next;
		}
	}
}