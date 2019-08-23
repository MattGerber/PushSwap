/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:39 by magerber          #+#    #+#             */
/*   Updated: 2019/08/23 12:39:33 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stacka)
{
	stacka = find_list_head(stacka);
	while (stacka->next != NULL)
	{
		if (stacka->value > stacka->next->value)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

int		num_input_check(char **nums)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
