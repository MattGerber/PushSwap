/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:57 by magerber          #+#    #+#             */
/*   Updated: 2019/09/03 15:30:30 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*initialise_stack(int count, char **args, int 	i)
{
	t_stack	*stack;
	
	stack = NULL;

	while (i < count)
	{
		stack = make_new_node(stack, ft_atoi(args[i]));
		i++;
	}
	return (stack);
}

t_stack	*make_new_node(t_stack *head, int value)
{
	t_stack	*temp;
	t_stack	*newnode;

	if (head == NULL)
	{
		head = malloc(sizeof(t_stack));
		head->previous = NULL;
		head->next = NULL;
		head->value = value;
	}
	else
	{
		newnode = malloc(sizeof(t_stack));	
		temp = head;
		while (temp->next)
			temp= temp->next;
		temp->next = newnode;
		newnode->previous = temp;
		newnode->next = NULL;
		newnode->value = value;
	}
	return(head);
}

int		stack_length(t_stack **stack)
{
	int i;
	t_stack *temp;

	i = 1;
	temp = (*stack);
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	clean_stack(t_stack *stacka, t_stack *stackb)
{
	t_stack	*freeme;
	t_stack *holdme;
		
	if (stacka != NULL)
	{
		freeme = (stacka);
		holdme = NULL;
		while (freeme->next != NULL)
		{
			holdme = freeme->next;
			free(freeme);
			freeme = holdme;
		}
	}
	if (stackb != NULL)
	{
		freeme = (stackb);
		holdme = NULL;
		while (freeme->next != NULL)
		{
			holdme = freeme->next;
			free(freeme);
			freeme = holdme;
		}
	}
}

void	print_stack(t_stack *start)
{
	t_stack	*currentnode;
	int		count;
	
	if (start != NULL)
	{
		count = 0;
		currentnode = start;
		while (currentnode)
		{
			count++;
			printf("item %d = %d\n", count, currentnode->value);
			currentnode = currentnode->next;
		}
	}
}
