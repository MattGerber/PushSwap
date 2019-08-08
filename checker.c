/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/08/08 11:21:20 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack		*initialise_stack(int count, char **args)
{
	t_stack	*stack;
	int 	i;

	stack = NULL;
	
	// printf("%d", stacka->value);
	i = 1;
	while (i < count)
	{
		if(stack == NULL)
		{
			stack = make_new_node(NULL, ft_atoi(args[i])); 
			//stackb->value = 0;
			stack->value = ft_atoi(args[i]);
			i++;
		}
		else
		{
			stack = make_new_node(stack, ft_atoi(args[i]));
			stack->value = ft_atoi(args[i]);
			i++;
		}
	}
	return(stack);
}

int		main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = initialise_stack(argc, argv);
	stackb = NULL;
	

	//print_stack(stackb);
	printf("1\n");
	print_stack(stacka);
	printf("2\n");
	pb(find_list_head(stacka), stackb);
	printf("3\n");
		print_stack(stacka);
	printf("4\n");
	print_stack(stackb);
	printf("5\n");
	pb(find_list_head(stacka),find_list_head(stackb));
		print_stack(stacka);
	printf("6\n");
	print_stack(stackb);
	pb(find_list_head(stacka),find_list_head(stackb));
	printf("7\n");
		print_stack(stacka);
	printf("8\n");
	print_stack(stackb);
	pb(find_list_head(stacka),find_list_head(stackb));
	printf("9\n");
		print_stack(stacka);
	printf("10\n");
	print_stack(stackb);
	pa(find_list_head(stackb),find_list_head(stacka));
	printf("11\npb");
	print_stack(stacka);
	printf("12\n");
	print_stack(stackb);
	
	printf("13\n");
	clean_stack(find_list_head(stacka));
} 
