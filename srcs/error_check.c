/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:39 by magerber          #+#    #+#             */
/*   Updated: 2019/09/04 12:08:42 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *stacka, t_stack *stackb)
{
	if (stackb != NULL || stacka == NULL)
		return (0);
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
			if (!ft_isdigit(nums[i][j]) || ft_atol(&nums[i][j]) > 2147483647 
			|| ft_atol(&nums[i][j]) <= -2147483648)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		input_dupe_check(char **nums)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while(nums[i])
	{
		j = 0;
		while (nums[j])
		{
			if (ft_strequ(nums[i], nums[j]) && i != j)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

