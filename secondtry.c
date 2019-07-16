#include "libft/libft.h"

typedef struct s_stack
{
	int 			value;
	struct	s_stack *next;
}			t_stack;

t_stack	*addnode(t_stack *previous)
{
	t_stack *newnode;

	newnode = malloc(sizeof(t_stack));
	previous->next = newnode;
	newnode->next = NULL;

	return(newnode);
}

void	PrintStack(t_stack	*start)
{
	t_stack	*currentnode = start;
	int		count;

	while (currentnode->next != NULL)
	{
		count++;
		printf("item %d = %d", count, currentnode->value);
		currentnode = currentnode->next;
	}
}

void	CleanStack(t_stack *start)
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

int		main(int argc, char **argv)
{
	t_stack *stacka;
	int i = 1;

	stacka = malloc(sizeof(t_stack));
	while(i < argc)
	{
		stacka = addnode(stacka);
		stacka->value = ft_atoi(argv[i]);	
		i++;
	}

	PrintStack(stacka);
	CleanStack(stacka);
	// stacka = malloc(sizeof(t_stack));
	// stacka->value = ft_atoi(argv[1]);
	// stacka->next = NULL;
	// printf("work: %d", stacka->value);
	// free(stacka);
	return (0);
}