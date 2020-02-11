/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:51:57 by magerber          #+#    #+#             */
/*   Updated: 2020/01/28 11:22:20 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void		stack_add_head(t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	if (!(head) || (!(node)))
		return ;
	tmp = *head;
	if (tmp)
	{
		tmp->previous= node;
		node->next = *head;
		node->previous = NULL;
		*head = node;
	}
	else
	{
		node->next = NULL;
		node->previous= NULL;
		*head = node;
	}
}

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
		// head->weight = 0;
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
		// head->weight = 0;
	}
	return(head);
}

int		stack_length(t_stack **stack)
{
	int i;
	t_stack *temp;

	i = 1;
	temp = (*stack);
	if ((*stack))
	{
		while (temp->next != NULL)
		{
			i++;
			temp = temp->next;
		}
		return (i);
	}
	else 
		return(0);
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
			ft_putstr("item ");
			ft_putnbr(count);
			ft_putstr(" = ");
			ft_putnbr(currentnode->value);
			ft_putendl("");
			currentnode = currentnode->next;
			// "item %d = %d\n", count, currentnode->value);
		}
	}
	else
	{
		ft_putendl("NULL");
	}
	
}

void	print_weight(t_stack *start)
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
			ft_putstr("item ");
			ft_putnbr(count);
			ft_putstr(" = ");
			ft_putnbr(currentnode->value);
			ft_putendl("");
			currentnode = currentnode->next;
			// "item %d = %d\n", count, currentnode->value);
		}
	}
}
