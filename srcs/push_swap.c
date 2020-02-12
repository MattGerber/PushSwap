/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:26:40 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 15:10:10 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

 void		free_nums(char **numbers)
 {
	 int i;
	 i = 0;
	 while(numbers[i])
	 {
	 	free(numbers[i]);
		 i++;
	 }
 }

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
	start_push_swap(stacka, stackb);
	if (argc == 2)
		free_nums(numbers);
}
