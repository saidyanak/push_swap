#include "push_swap.h"

void    move_b_to_a(t_list **stack_a, t_list **stack_b)
{
    set_top_node(stack_a, (*stack_b)->taget, 'a');
    actions(stack_a, stack_b, "pa");
}

void	set_target_b(t_list *stack_a, t_list *stack_b, int a_len,int b_len)
{
	t_list	*current_a;
	t_list	*target_node;
	int		best_index;

	current_a =stack_a;
	while (b_len-- != 0)
	{
		best_index = 2147483647;
		a_len = lst_len(stack_a);
		while (a_len-- != 0)
		{
			if (current_a->data > stack_b->data
				&& current_a->data < best_index)
			{
				best_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == 2147483647)
			stack_b->taget = find_min(stack_a);
		else
			stack_b->taget = target_node;
		stack_b = stack_b->next;
	}
}

void    prepare_stack_b(t_list *stack_a, t_list *stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
	if (stack_b->next == NULL)
    	set_target_b(stack_a, stack_b, lst_len(stack_a), 1);
	else
		set_target_b(stack_a, stack_b, lst_len(stack_a),  lst_len(stack_b));
}

void    move_stack_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        prepare_stack_b(*stack_a, *stack_b);
        move_b_to_a(stack_a, stack_b);
    }
}
