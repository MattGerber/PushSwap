/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:26:40 by magerber          #+#    #+#             */
/*   Updated: 2020/01/28 12:21:02 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

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

void		sort_five(t_stack *stacka, t_stack *stackb)
{
	while(stack_length(&stackb) < 3)
	{
		if(stacka->weight == 5 || stacka->weight == 4)
			ra(&stacka, 1);
		else 
			pb(&stacka, &stackb, 1);
	}
	while(!sorted(stackb))
	{
		if(stackb->value < stackb->next->next->value)
			rb(&stackb, 1);
		else 
			sb(&stackb, 1);
	}	
	while(stackb)
		pa(&stacka, &stackb, 1);
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
	if (stack_length(&stacka) == 3)
		sort_three_asc(&stacka, &stackb);
	else if (stack_length(&stacka) == 5)
		sort_five(stacka, stackb);
	else
		sort_stack(&stacka, &stackb);
}
