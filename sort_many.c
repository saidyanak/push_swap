#include "push_swap.h"

void	set_index(t_list *stack)
{
	int		i;
	int 	median;
	t_list	*head;

	head = stack;
	if (stack->next == NULL)
		return;
	median = lst_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= median)
			stack->median = 1;
		else
			stack->median = 0;
		if (stack->next == NULL)
			return;
		stack = stack->next;
		i++;
		if (head == stack)
			break;
	}
}

static void	min_on_top(t_list **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->data != find_min(*a)->data) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->median) //Rotate or reverse rotate according to the position of the node on the median
			actions(a,NULL, "ra");
		else
			actions(a,NULL, "rra");
	}
}

void	sort_many(t_list **stack_a, t_list **stack_b)
{
	actions(stack_a, stack_b, "pb");
	actions(stack_a, stack_b, "pb");
	move_stack_b(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	move_stack_a(stack_a, stack_b);
	set_index(*stack_a);
	min_on_top(stack_a);
}