#include "push_swap.h"

t_list	*find_min(t_list *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	t_list	*head;
	t_list	*min_node;
	long		min_number;

	min_number = LONG_MAX;
	head = stack;
	while (stack)
	{
		if (min_number > stack->data)
		{
			min_number = (long)stack->data;
			min_node = stack;
		}
		stack = stack->next;
		if (head == stack)
			return (min_node);

	}
	return (NULL);
}

t_list	*find_max(t_list *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	t_list	*head;
	t_list	*max_node;
	long		max_number;

	max_number = LONG_MIN;
	head = stack;
	while (stack)
	{
		if (max_number < stack->data)
		{
			max_number = (long)stack->data;
			max_node = stack;
		}
		stack = stack->next;
		if (head == stack)
			return (max_node);
	}
	return (NULL);
}
