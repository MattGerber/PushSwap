/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/09/03 15:37:02 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
		print_stack(stackb);
		ft_putendl(command);
		print_stack(stacka);
	 	free(command);
	}
	ft_putstr("\n\n");
	print_stack(stacka);
	//print_stack(stacka);
	if (is_sorted(stacka, stackb))
		ft_putendl("OK");
	else
		ft_putendl("KO");

	clean_stack(stacka, stackb);
	//clean_stack( (stackb));
}
