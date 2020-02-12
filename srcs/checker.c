/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:41:09 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 15:10:18 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int		main(int argc, char **argv)
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
		free(numbers);
	}
	else
	{
		numbers = argv;
		if (errors(numbers))
			stacka = initialise_stack(numbers, 1);
		else
			return (0);
	}
	start_checker(stacka, stackb);
	clean_stack(stacka, stackb);
}
