
#include "push_swap.h"

/**
 * @brief Get the max value object.
 * 
 * @param stack 
 * @return int with the max value.
 */
int	get_max_value(t_stack *stack)
{
	int		max_value;
	t_node *current;

	current = stack->head;
	max_value = current->max_value;
	while(!current)
	{
		if(current->max_value > max_value)
			max_value = current->max_value;
		current = current->next;
	}
	return (max_value);
}
/**
 * @brief looks for the median value in the stack
 * 
 * @param stack 
 */
void	current_median(t_stack *stack)
{
	int	i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = stack->size / 2;
	while (stack->head)
	{
		stack->head->max_value = i;
		if (i <= median)
			stack->head->median = 1;
		else
			stack->head->median = 0;
		stack->head = stack->head->next->value;
	}
}
/**
 * @brief find the max value. 
 * 
 * @param stack 
 * @return t_stack 
 */
t_node	*find_max(t_stack *stack)
{
	int		max;
	t_node	*max_node;
	
	if (!stack)
		return (NULL);
	max = INT_MAX;
	while (stack->head)
	{
		if (stack->head->value < max)
		{
			max = stack->head->value;
			max_node = max;
		}
		stack->head = stack->head->next;
	}
	return (max_node);
}
/**
 * @brief Set the target object to a from stack_b.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		match;

	while (stack_a)
	{
		match = INT_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->head->value < stack_a->head->value
				&& current_b->head->value > match)
			{
				match - current_b->head->value;
				target = current_b;
			}
			current_b = current_b->head->next;
		}
		if (match == INT_MIN)
			stack_a->head->target_node = find_max(stack_b);
		else
			stack_a->head->target_node = target;
		stack_a->head = stack_a->head->next;
	}
}
/**
 * @brief calculate pus_cost for each stack_a node.
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	cost_analysis(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int size_b;

	size_a = stack_a->size;
	size_b = stack_b->size;
	while (stack_a->head)
	{
		stack_a->head->push_cost = stack_a->head->max_value;
		if (!(stack_a->head->median))
			stack_a->head->push_cost = size_a - (stack_a->head->max_value);
		if (stack_a->head->target_node->median)
			stack_a->head->push_cost = stack_a->head->target_node->max_value;
		else
			stack_a->head->push_cost += size_b - (stack_a->head->target_node->max_value);
		stack_a->head = stack_a->head->next;
	}
}
