/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:26:40 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 14:07:34 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	**numbers;

	stackb = NULL;
	if (argc == 2)
	{
		numbers = ft_strsplit(argv[1], ' ');
		if (errors(numbers))
			stacka = initialise_stack(numbers, 0);
		else
			return (0);
	}
	else
	{
		numbers = argv;
		if (errors(numbers))
			stacka = initialise_stack(numbers, 1);
		else
			return (0);
	}
		free(numbers);
	start_push_swap(stacka, stackb);
		// clean_stack(stacka, stackb);
	while(1){}
}
