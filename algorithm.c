
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if(!stack)
		return (1);
	while(stack->head->next)
	{
		if(stack->head->value > stack->head->next->value)
			return (0);
		stack->head = stack->head->next;
	}
}

void	sort3(t_stack **stack)
{
	t_node	*current;

	current = get_max_value(*stack);
	if(current->max_value == *stack)
		ra_mov(stack);
	else if((*stack)->head->next == current->max_value)
		rra_mov(stack);
	if((*stack)->head > (*stack)->head->next)
		sa_mov(stack);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int size_a;

	size_a = (*stack_a)->size;
	if(size_a-- > 3 && is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	if(size_a-- > 3 && is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	while(size_a-- > 3 && is_sorted(*stack_a))
}