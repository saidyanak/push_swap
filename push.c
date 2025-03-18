/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:47:27 by syanak            #+#    #+#             */
/*   Updated: 2025/03/18 15:14:21 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if ((*stack_b)->next == NULL)
	{
		second_last_node(*stack_a)->next = *stack_b;
		(*stack_b)->next = (*stack_a);
		*stack_a = *stack_b;
	}
	else
	{
		tmp = *stack_b;
		second_last_node(*stack_b)->next = (*stack_b)->next;
		*stack_b = (*stack_b)->next;
		second_last_node(*stack_a)->next = tmp;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
	{
		tmp = second_last_node(*stack_a);
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_a;
		(*stack_b)->next = NULL;
		return ;
	}
		tmp = *stack_a;
		second_last_node(*stack_a)->next = (*stack_a)->next;
		*stack_a = (*stack_a)->next;
		if ((*stack_b)->next == NULL)
		{
			(*stack_b)->next = tmp;
			tmp->next = *stack_b;
			*stack_b = tmp;
			return ;
		}
		second_last_node(*stack_b)->next = tmp;
		tmp->next = *stack_b;
		*stack_b = tmp;
}


char	*push(t_list **stack_a, t_list **stack_b, char *strig)
{
	if (strig[1] == 'a')
		push_a(stack_a, stack_b);
	else if (strig[1] == 'b')
		push_b(stack_a, stack_b);
	return (strig);
}
