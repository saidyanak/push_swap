#include "push_swap.h"

int	max_data(t_list *stack_a)
{
	int		number;
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	len = lst_len(stack_a);
	tmp = stack_a;
	number = stack_a->data;
	while (i < len)
	{
		if (number < stack_a->data)
			number = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	return (number);
}

int	min_data(t_list *stack_a)
{
	int		number;
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	len = lst_len(stack_a);
	tmp = stack_a;
	number = stack_a->data;
	while (i < len)
	{
		if (number > stack_a->data)
		number = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	return (number);
}

void	sort_two(t_list **stack_a)
{
	actions(stack_a, NULL, "sa");
}

void	sort_three(t_list **stack_a)
{
	while (!(is_sorted(*stack_a)))
	{
		if ((*stack_a)->data == max_data(*stack_a) && (*stack_a)->next->data == min_data(*stack_a))
			actions(stack_a, NULL, "ra");
		else if ((*stack_a)->data > (*stack_a)->next->data)
			actions(stack_a, NULL, "sa");
		else if ((*stack_a)->data < (*stack_a)->next->data)
			actions(stack_a, NULL, "rra");
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	actions(stack_a, stack_b, "pb");// pb pb rrb pb pa pa rra pa
	sort_three(stack_a);
	if ((*stack_b)->data > max_data(*stack_a))
	{
		actions(stack_a, stack_b, "pa");
		actions(stack_a, stack_b, "ra");
	}
	else if (((*stack_b)->data > (*stack_a)->data) && ((*stack_b)->data > (*stack_a)->next->data))
	{
		actions(stack_a, stack_b, "rra");
		actions(stack_a, stack_b, "pa");
		actions(stack_a, stack_b, "rra");
		actions(stack_a, stack_b, "rra");
	}
	else if ((*stack_b)->data > (*stack_a)->data && ((*stack_b)->data < (*stack_a)->next->data) )
	{
		actions(stack_a, stack_b, "pa");
		actions(stack_a, stack_b, "sa");
	}
	else if ((*stack_b)->data < min_data(*stack_a))
		actions(stack_a, stack_b, "pa");
}