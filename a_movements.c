
#include "push_swap.h"

void	ft_sa(t_stack *stack_a)
{
    t_node  *swap;

    swap = stack_a ->head;
    stack_a->head = stack_a->head->next;
    stack_a->head->next = swap;
    swap->next = NULL;
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node *swap;

	swap = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_a->head = swap;
	swap->next = NULL;
}

void	ft_ra(t_stack *stack_a)
{
	t_node *swap;
	t_node *rotation;

	swap = stack_a->head;
	rotation = stack_a->head;
	while (rotation->next)
		rotation = rotation->next;
	rotation->next = swap;
	swap->next = NULL;
}

void	ft_rra(t_stack *stack_a)
{
	t_node *prev_node;
	t_node *r_rotation;

	prev_node = NULL;
	r_rotation = stack_a->head;
	while (r_rotation->next)
	{
		prev_node = r_rotation;
		r_rotation = r_rotation->next;
	}
	prev_node->next = NULL;
	r_rotation->next = stack_a->head;
	stack_a->head = r_rotation;
}