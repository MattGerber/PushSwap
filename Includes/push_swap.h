/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:50:20 by magerber          #+#    #+#             */
/*   Updated: 2019/09/12 10:50:00 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

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
void				sa(t_stack **listhead, int i);
void				sb(t_stack **listhead, int i);
void				ss(t_stack **listheada, t_stack **listheadb, int i);
void				pb(t_stack **lista, t_stack **listb, int i);
void				pa(t_stack **lista, t_stack **listb, int i);
void				ra(t_stack **stacka, int i);
void				rb(t_stack **stackb, int i);
void				rr(t_stack **stacka, t_stack **stackb, int i);
void				rra(t_stack **stacka, int i);
void				rrb(t_stack **stackb, int i);
void				rrr(t_stack **stacka, t_stack **stackb, int i);
int					is_sorted(t_stack *stacka, t_stack *stackb);
int					num_input_check(char **nums);
void				do_op(char *command, t_stack **stacka, t_stack **stackb);
int					input_dupe_check(char **nums);
int					stack_length(t_stack **stack);
void				sort_ineffeciently(t_stack **lista,t_stack **listb, int start, int end);
void				sort_three(t_stack **lista,t_stack **listb);
void				sort_V2(t_stack **lista,t_stack **listb);

#endif
