/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <magerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:50:20 by magerber          #+#    #+#             */
/*   Updated: 2020/02/12 18:00:17 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				weight;
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

typedef struct		s_bestmove
{
	int				a_move;
	int				b_move;
	int				total;
}					t_bestmove;

t_stack				*initialise_stack(char **args, int i);
void				print_stack(t_stack	*start);
void				clean_stack(t_stack *stacka, t_stack *stackb);
t_stack				*make_new_node(t_stack *previous, int value);
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
int					is_sorted_asc(t_stack *stacka, t_stack *stackb);
int					num_input_check(char **nums);
void				do_op(char *command, t_stack **stacka, t_stack **stackb);
int					input_dupe_check(char **nums);
int					stack_length(t_stack **stack);
void				sort_ineffeciently(t_stack **lista, t_stack **listb,
											int start, int end);
void				sort_three_asc(t_stack **lista, t_stack **listb);
int					is_sorted_des(t_stack *stacka, t_stack *stackb);
void				sort_three_des(t_stack **lista, t_stack **listb);
int					find_biggest(t_stack *stacka);
int					find_smallest(t_stack *stacka);
int					push_biggest(t_stack *stacka);
int					push_smallest(t_stack *stacka);
void				sort_stack(t_stack **stacka, t_stack **stackb);
int					calculate_bmove(t_stack *stackb, int numweight);
int					sorted(t_stack *stack);
void				stack_add_head(t_stack **head, t_stack *node);
int					execute_move(t_stack **list, int i, char c);
void				algo_pushback(t_stack **stacka, t_stack **stackb);
void				execute_both(t_bestmove *move, t_stack **stacka,
									t_stack **stackb);
void				initialise_struct(t_bestmove *best, t_bestmove *current);
void				set_move(t_stack *stackb, t_stack *a, t_bestmove *current);
void				start_checker(t_stack *stacka, t_stack *stackb);
int					errors(char **numbers);
void				start_push_swap(t_stack *stacka, t_stack *stackb);
void				add_num_weight(t_stack **stacka);
void				sort_five(t_stack *stacka, t_stack *stackb);
void				free_nums(char **numbers);

#endif
