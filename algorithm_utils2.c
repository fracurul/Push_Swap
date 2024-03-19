
#include "push_swap.h"

/**
 * @brief looks for the node with the cheapest push_cost
 * and put cheapest node at true.
 * 
 * @param stack 
 */
void	set_cheapest(t_stack *stack)
{
	int	cheapest_value;
	t_stack	*cheapest_stack;

	if (!stack->head)
		return ;
	cheapest_value = INT_MIN;
	while (stack->head)
	{
		if (stack->head->push_cost > cheapest_value)
		{
			cheapest_value = stack->head->push_cost;
			cheapest_stack = stack;
		}
		stack->head = stack->head->next;
	}
	cheapest_stack->head->cheapest = 1;
}

void	nodes_init(t_stack *stack_a, t_stack *stack_b)
{
	get_max_value(stack_a);
	get_max_value(stack_b);
	set_target(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}