/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/09/09 13:44:12 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include <stdio.h>

void	do_op(char *command, t_stack **stacka, t_stack **stackb)
{
	if (ft_strequ(command, "pb"))      //if (command ==  "pb")
		pb(stacka, stackb, 0);
 	else if (ft_strequ(command, "pa"))
 		pa(stackb, stacka, 0);
 	else if (ft_strequ(command, "sa"))
 		sa(stacka, 0);
 	else if (ft_strequ(command, "ss"))
 		ss(stacka, stackb, 0);
 	else if (ft_strequ(command, "sb"))
 		sb(stackb, 0);
 	else if (ft_strequ(command, "ra"))
 		ra(stacka, 0);
	else if (ft_strequ(command, "rb"))
		rb(stackb, 0);
 	else if (ft_strequ(command, "rr"))
		rr(stacka, stackb, 0);
	else if (ft_strequ(command, "rra"))
		rra(stacka, 0);
	else if (ft_strequ(command, "rrb"))
		rrb(stackb, 0);
	else if (ft_strequ(command, "rrr"))
		rrr(stacka, stackb, 0);
}

int		main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb = NULL;
	char	*command;
	char	**numbers;
	int		i;

	i = 0;
	if (argc == 2)
	{
		numbers = ft_strsplit(argv[1], ' ');
		if (!num_input_check(numbers) ||  !input_dupe_check(numbers))
		{
			ft_putstr("Error\n");
			return(0);			
		}
		while(numbers[i] != NULL)
			i++;
		stacka = initialise_stack(i, numbers, 0);
	//	stackb = make_new_node(NULL, 0);
		free (numbers);
			
	}
	else
	{
		numbers = argv;
		if (!num_input_check(numbers) ||  !input_dupe_check(numbers))
		{
			ft_putstr("Error\n");
			return(0);			
		}
		stacka = initialise_stack(argc, numbers, 1);
	//	stackb = make_new_node(NULL, 0);
	}
	while (get_next_line(0, &command))
	{
		do_op(command, &stacka, &stackb);
		// ft_putendl(command);
		//print_stack(stacka);
	 	free(command);
	}
		// ft_putstr("\n\n");
		// print_stack(stackb);
	if (is_sorted(stacka, stackb))
	 {
		//  print_stack(stacka);
		ft_putendl("OK");
	 }
	else
	{
		// print_stack(stacka);
		ft_putendl("KO");
	}

	clean_stack(stacka, stackb);
	//clean_stack( (stackb));
}
