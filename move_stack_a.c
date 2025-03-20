#include "push_swap.h"

void    set_target_b(t_list *stack_a, t_list *stack_b)
{
    
}

void    prepare_stack_b(t_list *stack_a, t_list *stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_target_b(stack_a, stack_b);
}

void    move_stack_a(t_list **stack_a, t_list **stack_b)
{
    while (stack_b)
    {
        prepare_stack_b(stack_a, stack_b);
        move_b_to_a();
    }
    
}