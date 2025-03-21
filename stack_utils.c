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


t_list	*get_cheapest(t_list *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	ft_if_same(t_list *head)
{
	t_list		*last;
	static int	j = 0;
	int			i;
	int arg_size;

	arg_size = lst_len(head);
	i = 0;
	if (arg_size < 2)
		return (0);
	last = head->next;
	while (i < (arg_size - 1))
	{
		if (head->data == last->data)
		{
			return (ft_free(NULL, head, arg_size, 0), exit(1), 1);
		}
		last = last->next;
		i++;
	}
	j++;
	if (j == (arg_size - 1))
		return (0);
	return (ft_if_same(head->next));
}