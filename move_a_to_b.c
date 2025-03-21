#include "push_swap.h"

void    set_top_node(t_list **lst, t_list *current, char stack)
{
    while (*lst != current)
    {
        if (stack == 'a')
        {
            if (current->median)
                actions(lst, NULL, "ra");
            else
                actions(lst, NULL, "rra");
        }
        else if (stack == 'b')
        {
            if (current->median)
                actions(NULL, lst, "rb");
            else
                actions(NULL, lst, "rrb");
        }
    }
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

void    both(t_list **stack_a, t_list **stack_b, t_list *current, char* action)
{
    while ((*stack_a) != current && (*stack_b) != current->taget)
        actions(stack_a,stack_b, action);
    set_index(*stack_a);
    set_index(*stack_b);
}

void    move_a_to_b(t_list **stack_a, t_list **stack_b)
{
    t_list *current;

    current = get_cheapest(*stack_a);
    if (current->median && current->taget->median)
        both(stack_a, stack_b, current, "rr");
    else if (!(current->median) && !(current->taget->median))
        both(stack_a, stack_b, current, "rrr");
    set_top_node(stack_a, current, 'a');
    set_top_node(stack_b, current->taget, 'b');
    actions(stack_a, stack_b, "pb");
}
