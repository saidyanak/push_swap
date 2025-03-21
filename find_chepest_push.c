#include "push_swap.h"

void	set_target_a(t_list *stack_a, t_list *stack_b, int a_len,int b_len)
{
	t_list	*current_b;
	t_list	*target_node;
	int		best_index;


	while (a_len-- != 0)
	{
		best_index = -2147483648;
		b_len = lst_len(stack_b);
		current_b =stack_b;
		while (b_len-- != 0)
		{
			if (current_b->data < stack_a->data
			&& current_b->data > best_index)
			{
				best_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == -2147483648)
			stack_a->taget = find_max(stack_b);
		else
			stack_a->taget = target_node;
		stack_a = stack_a->next;
	}
}

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
void	cost_analysis_a(t_list *stack_a, t_list *stack_b)
{
	int	a_len;
	int	b_len;

	a_len = lst_len(stack_a);
	b_len = lst_len(stack_b);
	while (a_len-- != 0)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->median))
			stack_a->cost = a_len - (stack_a->index);
		if (stack_a->taget->median)
			stack_a->cost += stack_a->taget->index;
		else
			stack_a->cost += b_len - (stack_a->taget->index);
		stack_a = stack_a->next;
	}

}

void		set_cheapest(t_list *stack_a)
{
	int		a_len;
	int		min_cost;
	t_list	*min_node;

	min_cost = 2147483647;
	a_len = lst_len(stack_a);
	while (a_len-- != 0)
	{
		if (stack_a->cost < min_cost)
		{
			min_cost = stack_a->cost;
			min_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	min_node->cheapest = 1;
}

void	prepare_stack_a(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_a(stack_a, stack_b, lst_len(stack_a), lst_len(stack_b));
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	find_chepest_push(t_list **stack_a, t_list **stack_b)
{
	while (lst_len(*stack_a) > 3 && !(is_sorted(*stack_a)))
	{
		prepare_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
}
