/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/08/23 12:39:46 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	do_op(char *command, t_stack *stacka, t_stack *stackb)
{
	if (ft_strequ(command, "pb"))
		pb(find_list_head(stacka), find_list_head(stackb));
	else if (ft_strequ(command, "pa"))
		pa(find_list_head(stackb), find_list_head(stacka));
	else if (ft_strequ(command, "sa"))
		sa(find_list_head(stacka));
	else if (ft_strequ(command, "ss"))
		ss(find_list_head(stacka), find_list_head(stackb));
	else if (ft_strequ(command, "sb"))
		sb(find_list_head(stackb));
	else if (ft_strequ(command, "ra"))
		ra(find_list_head(stacka));
	else if (ft_strequ(command, "rb"))
		rb(find_list_head(stackb));
	else if (ft_strequ(command, "rr"))
		rr(find_list_head(stacka), find_list_head(stackb));
	else if (ft_strequ(command, "rra"))
		rra(find_list_head(stacka));
	else if (ft_strequ(command, "rrb"))
		rrb(find_list_head(stackb));
	else if (ft_strequ(command, "rrr"))
		rrr(find_list_head(stacka), find_list_head(stackb));
}

t_stack	*initialise_stack(int count, char **args)
{
	t_stack	*stack;
	int 	i;

	stack = NULL;
	// printf("dfsa");
	i = 1;
	while (i < count)
	{
		if (stack == NULL)
		{
			stack = make_new_node(NULL, 0); 
			//stackb->value = 0;
		}
		else
		{
			stack = make_new_node(stack, ft_atoi(args[i]));
			i++;
		}
	}
	return (stack);
}

int		main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	*command;

	if (!num_input_check(argv))
	{
		ft_putstr("Error\n");
		return(0);			
	}
	stacka = initialise_stack(argc, argv);
	stackb = make_new_node(NULL, 0);
	 while (get_next_line(0, &command))
	{
		do_op(command, stacka, stackb);
		print_stack(stacka);
		print_stack(stackb);
	 	free(command);
	}
	print_stack(stacka);
	if (is_sorted(stacka))
		printf("yas");
	else
		printf("nah");
	//print_stacks(stacka, stackb);
	// printf("1\n");
	// print_stacks(stacka, stackb);
	// printf("2\n");
	// pb(find_list_head(stacka), find_list_head(stackb));
	// printf("3\n");
	// 	print_stacks(stacka, stackb);
	// printf("4\n");
	// print_stacks(stacka, stackb);
	// printf("5\n");
	// pb(find_list_head(stacka),find_list_head(stackb));
	// 	print_stacks(stacka, stackb);
	// printf("6\n");
	// print_stacks(stacka, stackb);
	// pb(find_list_head(stacka),find_list_head(stackb));
	// printf("7\n");
	// 	print_stacks(stacka, stackb);
	// printf("8\n");
	// print_stacks(stacka, stackb);
	// pb(find_list_head(stacka),find_list_head(stackb));
	// printf("9\n");
	// 	print_stacks(stacka, stackb);
	// printf("10\n");
	// print_stacks(stacka, stackb);
	// pa(find_list_head(stackb),find_list_head(stacka));
	// printf("11\npb");
	// print_stacks(stacka, stackb);
	// printf("12\n");
	// print_stacks(stacka, stackb);
	// printf("13\n");
	// clean_stack(find_list_head(stacka));
}
