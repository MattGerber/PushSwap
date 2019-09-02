/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:50:20 by magerber          #+#    #+#             */
/*   Updated: 2019/08/29 15:01:13 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct		s_stack
{ 
	//int				head;
	int				weight;
 	int				value;
 	struct s_stack	*next;
 	struct s_stack	*previous;
}					t_stack;

// void				print_stacks(t_stack *stacka, t_stack *stackb);
t_stack				*initialise_stack(int count, char **args, int 	i);
void				print_stack(t_stack	*start);
void				clean_stack(t_stack *stacka, t_stack *stackb);
t_stack				*make_new_node(t_stack *previous, int value);
//t_stack				**find_list_head(t_stack *node);
void				sa(t_stack **listhead);
void				sb(t_stack **listhead);
void				ss(t_stack **listheada, t_stack **listheadb);
void				pb(t_stack **lista, t_stack **listb);
void				pa(t_stack **lista, t_stack **listb);
void				ra(t_stack **stacka);
void				rb(t_stack **stackb);
void				rr(t_stack **stacka, t_stack **stackb);
void				rra(t_stack **stacka);
void				rrb(t_stack **stackb);
void				rrr(t_stack **stacka, t_stack **stackb);
int					is_sorted(t_stack *stacka, t_stack *stackb);
int					num_input_check(char **nums);
void				do_op(char *command, t_stack **stacka, t_stack **stackb);
int					input_dupe_check(char **nums);
int					stack_length(t_stack **stack);

#endif