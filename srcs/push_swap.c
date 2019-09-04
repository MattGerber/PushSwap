/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:26:40 by magerber          #+#    #+#             */
/*   Updated: 2019/09/04 12:45:40 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		add_num_weight(t_stack **stacka)
{
	t_stack *temp;
	t_stack *compare;

	compare = (*stacka);
	while (compare)
	{
		compare->weight = 1;
		compare = compare->next;
	}
	compare = (*stacka);
	while(compare)
	{
		temp = (*stacka);
		while(temp)
		{
			if (compare->value > temp->value)
				compare->weight++;
			temp = temp->next;			
		}
		compare = compare->next;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb = NULL;
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
	}
	add_num_weight(&stacka);
	print_stack(stacka);
}
