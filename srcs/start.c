/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:04:31 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 13:48:56 by magerber         ###   ########.fr       */
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
	while (compare)
	{
		temp = (*stacka);
		while (temp)
		{
			if (compare->value > temp->value)
				compare->weight++;
			temp = temp->next;
		}
		compare = compare->next;
	}
}

void		do_op(char *command, t_stack **stacka, t_stack **stackb)
{
	if (ft_strequ(command, "pb"))
		pb(stacka, stackb, 0);
	else if (ft_strequ(command, "pa"))
		pa(stacka, stackb, 0);
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
	else
		ft_putendl("ERROR");
}

int			errors(char **numbers)
{
	if (!num_input_check(numbers) || !input_dupe_check(numbers))
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
		return (1);
}

void		start_checker(t_stack *stacka, t_stack *stackb)
{
	char	*command;

	while (get_next_line(0, &command))
	{
		do_op(command, &stacka, &stackb);
		free(command);
	}
	if (is_sorted_asc(stacka, stackb))
	{
		ft_putendl("OK");
	}
	else
	{
		ft_putendl("KO");
	}
}

void		start_push_swap(t_stack *stacka, t_stack *stackb)
{
	if(!is_sorted_asc(stacka, stackb))
	{
		add_num_weight(&stacka);
		if (stack_length(&stacka) == 3)
			sort_three_asc(&stacka, &stackb);
		else if (stack_length(&stacka) == 5)
			sort_five(stacka, stackb);
		else
			sort_stack(&stacka, &stackb);
	}
}
