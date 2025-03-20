#include "push_swap.h"

void	set_target_a(t_list *stack_a, t_list *stack_b, int a_len,int b_len)
{
	t_list	*current_b;
	t_list	*target_node;
	int		best_index;

	
	current_b =stack_b;

	while (stack_a->index < a_len)
	{
		best_index = -2147483648;
		while (current_b->index != b_len)
		{
			if (stack_b->data < stack_a->data && stack_b->data > best_index)
			{
				best_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
			printf("set_target_a%d\n",current_b->index);

		}
		if (best_index == -2147483648)
			stack_a->taget = find_max(stack_b);
		else
			stack_a->taget = target_node;
		stack_a = stack_a->next;
		printf("set_target_a2.while\n");

	}
}

void	set_index(t_list *stack)
{
	int		i;
	int 	median;
	t_list	*head;

	head = stack;
	median = lst_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (stack->index < median)
			stack->median = 0;
		else
			stack->median = 1;
		stack = stack->next;
		i++;
		if (head == stack)
			break;
			printf("set_index\n");

	}
}
void	cost_analysis_a(t_list *stack_a, t_list *stack_b)
{
	int	a_len;
	int	b_len;
	
	a_len = lst_len(stack_a);
	b_len = lst_len(stack_b);
	while (stack_a->index < a_len)
	{
		stack_a->cost = stack_a->index;
		if (!stack_a->median)
			stack_a->cost = (a_len - stack_a->index); 
		if (stack_a->taget->median)
			stack_a->cost += stack_a->taget->index;
		else
			stack_a->cost += b_len - stack_a->taget->index;
		stack_a = stack_a->next;
		printf("cost_analysis_a\n");

	}
	
}

void		set_cheapest(t_list *stack_a)
{
	int		a_len;
	int		min_cost;
	t_list	*min_node;

	min_cost = 2147483647;
	a_len = lst_len(stack_a);
	while (stack_a->index < a_len)
	{
		if (stack_a->cost < min_cost)
		{
			min_cost = stack_a->cost;
			min_node = stack_a;
		}
		stack_a->next;
		printf("set_cheapest\n");

	}
	min_node->cheapest = 1;
}

void	prepare_stack_a(t_list *stack_a, t_list *stack_b)
{
	printf("prepare_stack_a\n");
	set_index(stack_a);
	set_index(stack_b);
	set_target_a(stack_a, stack_b, lst_len(stack_a), lst_len(stack_b));
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	find_chepest_push(t_list **stack_a, t_list **stack_b)
{
	while (lst_len(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		prepare_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
}
