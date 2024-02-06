/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:04 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/01 21:10:38 by fracurul         ###   ########.fr       */
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
	int				a_mov;
	int				b_mov;
	struct t_node	*next;
}					t_node;

typedef struct t_stack
{
	t_node			*head;
	int				size;
}					t_stack;

// movements//
// a_movements
void				sa_mov(t_stack *stack_a);
void				pa_mov(t_stack *stack_a, t_stack *stack_b);
void				ra_mov(t_stack *stack_a);
void				rra_mov(t_stack *stack_a);
// b_movements
void				sb_mov(t_stack *stack_b);
void				pb_mov(t_stack *stack_a, t_stack *stack_b);
void				rb_mov(t_stack *stack_b);
void				rrb_mov(t_stack *stack_b);
// double movements
void				ss_mov(t_stack *stack_a, t_stack *stack_b);
void				rr_mov(t_stack *stack_a, t_stack *stack_b);
void				rrr_mov(t_stack *stack_a, t_stack *stack_b);
//utils
long int	ft_atol(const char *str);
#endif