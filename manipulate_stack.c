/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:57 by magerber          #+#    #+#             */
/*   Updated: 2019/08/19 12:33:03 by magerber         ###   ########.fr       */
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
	new_stack->weight = 0;
	new_stack->head = 0;

	if (previous != NULL)
	{
		previous->next = new_stack;
		new_stack->previous = previous;
	}
	else
		new_stack->head = 1;

	return(new_stack);
}

int		stack_length(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->next != NULL)
	{
		i++;
		stack = stack->next;			
	}
	return (i);
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
	while (node->previous != NULL )
	{
		node = node->previous;
	}
	if (node->head = 1)
		node = node->next;
	return(node);
}

void	print_stack(t_stack	*start)
{
	t_stack	*currentnode;
	int		count;
	
	count = 0;
	currentnode = find_list_head(start);
	while (currentnode)
	{
		count++;
		printf("item %d = %d\n", count, currentnode->value);
		currentnode = currentnode->next;
	}
}