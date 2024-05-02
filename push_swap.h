/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:04 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:18:39 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/get_next_line_bonus.h"

typedef struct t_node
{
	int				value;
	int				max_value;
	int				push_cost;
	int				abv_avg;
	int				cheapest;
	struct t_node	*target_node;
	struct t_node	*next;
}					t_node;

typedef struct t_stack
{
	t_node			*head;
	int				size;
}					t_stack;

// movements //
//-> swap_movements.
void				ft_swap(t_stack **stack);
void				sa_mov(t_stack **stack_a);
void				sb_mov(t_stack **stack_b);
void				ss_mov(t_stack **stack_a, t_stack **stack_b);
//-> push_movements.
void				ft_push(t_stack **stack_a, t_stack **stack_b);
void				pa_mov(t_stack **stack_a, t_stack **stack_b);
void				pb_mov(t_stack **stack_a, t_stack **stack_b);
//-> rotation_movements.
void				ft_rotate(t_stack **stack_a);
void				ra_mov(t_stack **stack_a);
void				rb_mov(t_stack **stack_b);
void				rr_mov(t_stack **stack_a, t_stack **stack_b);
void				r_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest);
//-> reverse_rotations_movements.
void				ft_rrotation(t_stack **stack_a);
void				rra_mov(t_stack **stack_a);
void				rrb_mov(t_stack **stack_b);
void				rrr_mov(t_stack **stack_a, t_stack **stack_b);
void				rr_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest);
// parsing //
int					ft_parse_checker(int argc, char **argv);
int					ft_split_checker(int argc, char **argv);
int					*ft_parsing(int argc, char **argv);
// algorithm //
int					is_sorted(t_stack *stack);
void				stack_limits(int *min, int *max, t_node *node);
void				sort_three(t_stack **stack);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b);
// utils //
//-> parsing utils.
long				ft_atol(const char *str);
int					ft_isnbr(char *s);
int					ft_isdup(char **argv);
//-> node utils.
t_node				*create_node(int value);
void				node_to_tail(t_stack *stack, t_node *node);
void				nodes_init_a(t_stack *stack_a, t_stack *stack_b);
void				nodes_init_b(t_stack *stack_a, t_stack *stack_b);
void				array_free(char **array);
//-> stack utils.
void				stack_init(t_stack *stack);
void				stack_fill(t_stack *stack, int *parsing, int size);
void				delete_stack(t_stack *stack);
int					stack_size(t_stack *stack);
void				get_node_push(t_stack **stack, t_node *top_node, int n);
//->stack utils 2
t_node				*find_max(t_stack *stack);
t_node				*find_min(t_stack *stack);
t_node				*get_cheapest(t_stack *stack);
int					get_max_value(t_stack *stack);
//->algorithm utils
void				current_average(t_stack *stack);
void				set_target_a(t_stack *stack_a, t_stack *stack_b);
void				cost_analysis(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest(t_stack *stack);
//->algorithm utils 2
void				move_to_b(t_stack **stack_a, t_stack **stack_b);
void				move_to_a(t_stack **stack_a, t_stack **stack_b);
void				min_to_top(t_stack **stack_a);
void				set_target_b(t_stack *stack_a, t_stack *stack_b);
int					matrix_size(char **argv);
#endif