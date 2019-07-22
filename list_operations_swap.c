#include "push_swap.h"

void	sa(t_stack *listhead)
{
	t_stack	*nextelem;
	int		temp;

	nextelem = listhead->next;
	temp = listhead->value;
	listhead->value = nextelem->value;
	nextelem->value = temp;
}

