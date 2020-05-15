/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:39 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 11:55:34 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		is_sorted_asc(t_stack *stacka, t_stack *stackb)
{
	if (stackb != NULL || stacka == NULL)
		return (0);
	while (stacka->next)
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
		if (ft_atoi(nums[i]) == 0)
			return(0);
		while (nums[i][j])
		{
			if (ft_atol(&nums[i][j]) > 2147483647
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
	while (nums[i])
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

int		is_sorted_des(t_stack *stacka, t_stack *stackb)
{
	if (stackb != NULL || stacka == NULL)
		return (0);
	while (stacka->next != NULL)
	{
		if (stacka->value < stacka->next->value)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

int		sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
