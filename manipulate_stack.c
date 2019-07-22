#include "push_swap.h"

t_stack	*make_new_node(t_stack *previous)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	new_stack->next = NULL;
	new_stack->previous = NULL;

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
	while (node->previous != NULL )
	{
		node = node->previous;
	}
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