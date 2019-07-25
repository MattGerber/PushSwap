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

void	sb(t_stack *listhead)
{
	t_stack	*nextelem;
	int		temp;

	nextelem = listhead->next;
	temp = listhead->value;
	listhead->value = nextelem->value;
	nextelem->value = temp;
}

void	ss(t_stack *listheada, t_stack *listheadb)
{
	sa(listheada);
	sb(listheadb);
}