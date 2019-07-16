/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/07/16 16:35:25 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*MakeNewNode(t_stack *previous)
{
	t_stack	*Newstack;

	Newstack = malloc(sizeof(t_stack));
	Newstack->next = NULL;
	Newstack->previous = NULL;

	if (previous != NULL)
	{
		previous->next = Newstack;
		Newstack->previous = previous;
	}

	return(Newstack);
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

int		main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*heada;
	t_stack	*stackb;
	int 	i;

	stacka = NULL;
	stackb = NULL;
	heada = NULL;
	// printf("%d", stacka->value);
	i = 1;
	while (i < argc)
	{
		if(heada == NULL)
		{
			heada = MakeNewNode(NULL);
			stacka = heada;
			heada->value = ft_atoi(argv[i]);
			i++;
		}
		else
		{
			stacka = MakeNewNode(stacka);
			stacka->value = ft_atoi(argv[i]);
			i++;
		}
	}
	PrintStack(heada);
	CleanStack(stacka);

} 