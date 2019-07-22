/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2019/07/22 15:49:42 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int 	i;

	stacka = NULL;
	stackb = NULL;
	
	// printf("%d", stacka->value);
	i = 1;
	while (i < argc)
	{
		if(stacka == NULL)
		{
			stacka = make_new_node(NULL);
			stackb = make_new_node(NULL);
			stackb->value = 0;
			stacka->value = ft_atoi(argv[i]);
			i++;
		}
		else
		{
			stacka = make_new_node(stacka);
			stacka->value = ft_atoi(argv[i]);
			i++;
		}
	}
	print_stack(stackb);
	printf("\n");
	print_stack(stacka);
	printf("\n");
	sa(find_list_head(stacka));
	print_stack(stacka);
	printf("\n");
	clean_stack(stacka);
} 
