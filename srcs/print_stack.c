/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:19:00 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 13:03:02 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	print_stack(t_stack *start)
{
	t_stack	*currentnode;
	int		count;

	if (start != NULL)
	{
		count = 0;
		currentnode = start;
		while (currentnode)
		{
			count++;
			ft_putstr("item ");
			ft_putnbr(count);
			ft_putstr(" = ");
			ft_putnbr(currentnode->value);
			ft_putendl("");
			currentnode = currentnode->next;
		}
	}
	else
	{
		ft_putendl("NULL");
	}
}
