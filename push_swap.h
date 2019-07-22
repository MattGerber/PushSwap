/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:50:20 by magerber          #+#    #+#             */
/*   Updated: 2019/07/22 15:49:55 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct		s_stack
{
 	int				value;
 	struct s_stack	*next;
 	struct s_stack	*previous;
}					t_stack;

void	print_stack(t_stack	*start);
void	clean_stack(t_stack *start);
t_stack	*make_new_node(t_stack *previous);
t_stack *find_list_head(t_stack *node);
t_stack	*make_new_node(t_stack *previous);
void	sa(t_stack *listhead);

#endif
