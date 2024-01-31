

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct	t_node 
{
	int	value;
	int	a_mov;
	int	b_mov;
	struct t_node *next;
}	t_node;

typedef struct	t_stack
{
	t_node	*head;
	int	size;
}	t_stack;

									//movements//
//a_movements
void	ft_sa(t_stack *stack_a);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack_a);
void	ft_rra(t_stack *stack_a);
//b_movements
void	ft_sb(t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_rb(t_stack *stack_b);
void ft_rrb(t_stack *stack_b);

#endif