/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:21 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:54:37 by syanak           ###   ########.fr       */
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
	return ("ra\n");
}

char	*sa(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	last = second_last_node(*stack_a);
	tmp = (*stack_a)->next;
	if (lst_len(*stack_a) == 2)
	{
		*stack_a = (*stack_a)->next;
	}
	else
	{
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		last->next = *stack_a;
	}
	return ("sa\n");
}
#include <stdio.h>

char	*rra(t_list **stack_a)
{
	*stack_a = second_last_node(*stack_a);
	return ("rra\n");
}

void	actions(t_list **stack_a, t_list **stack_b, char *action)
{
	char	*message;

	if (compare_string("pb", action))
		;//message = pb();
	else if (compare_string("pa", action))
		;//message = pa();
	else if (compare_string("sa", action))
		message = sa(stack_a);
	else if (compare_string("sb", action))
		;//message = sb();
	else if (compare_string("ss", action))
		;//message = ss();
	else if (compare_string("ra", action))
		message = ra(stack_a);
	else if (compare_string("rb", action))
		;//message = rb();
	else if (compare_string("rr", action))
		;//message = rr();
	else if (compare_string("rra", action))
		message = rra(stack_a);
	else if (compare_string("rrb", action))
		;//message = rrb();
	else if (compare_string("rrr", action))
		;//message = rrr();
	write(1, message, ft_strlen(message));
}
