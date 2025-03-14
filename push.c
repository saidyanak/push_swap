#include "push_swap.h"

char	*push(t_list **stack_a, t_list **stack_b, char *strig)
{
	if (strig[1] == 'a')
		push_a(stack_a, stack_b);
	else if (strig[1] == 'b')
		push_b(stack_a, stack_b);
	return (strig);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{

}
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		second_last_node(*stack_a)->next = *stack_a;
		(*stack_b)->next = NULL;
	}
	else
	{
		
	}

}
