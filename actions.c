/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:21 by syanak            #+#    #+#             */
/*   Updated: 2025/03/21 03:46:10 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

int	compare_string(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (dst[i] == src[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ra(t_list **stack_a)
{
	*stack_a = (*stack_a)->next;
	return ("ra");
}

char	*sa(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	last = second_last_node(*stack_a);
	tmp = *stack_a;
	if (lst_len(*stack_a) == 2)
		*stack_a = (*stack_a)->next;
	else
	{
		last->next = (*stack_a)->next;
		(*stack_a) = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
	}
	return ("sa");
}

char	*rb(t_list **stack_b)
{
	*stack_b = (*stack_b)->next;
	return ("rb");
}
char	*rra(t_list **stack_a)
{
	*stack_a = second_last_node(*stack_a);
	return ("rra");
}
char	*rrb(t_list **stack_b)
{
	*stack_b = second_last_node(*stack_b);
	return ("rrb");
}

char	*rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return ("rr");
}

char	*rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	return ("rrr");
}

void	actions(t_list **stack_a, t_list **stack_b, char *action)
{
	char	*message;
	static int i = 0;


	if (compare_string("pa", action) || compare_string("pb", action))
		message = push(stack_a, stack_b, action);
	else if (compare_string("sa", action))
		message = sa(stack_a);
	else if (compare_string("ra", action))
		message = ra(stack_a);
	else if (compare_string("rb", action))
		message = rb(stack_b);
	else if (compare_string("rr", action))
		message = rr(stack_a, stack_b);
	else if (compare_string("rra", action))
		message = rra(stack_a);
	else if (compare_string("rrb", action))
		message = rrb(stack_b);
	else if (compare_string("rrr", action))
		message = rrr(stack_a, stack_b);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	i++;
	printf("%d\n",i);
}
