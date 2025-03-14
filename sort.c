/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:44 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:58:52 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <stdio.h>

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

void	sort_two(t_list **stack_a)
{
	actions(stack_a, NULL, "sa");
}

void	sort_many(t_list **stack_a, t_list **stack_b)
{
	actions(stack_a, stack_b, "pb");
	actions(stack_a, stack_b, "pb");
	push_b();
	sort_three(stack_a);
	push_a();
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	while (!is_sorted(*stack_a))
	{
		if (lst_len(*stack_a) == 1)
			return (0);
		else if (lst_len(*stack_a) == 2)
			sort_two(stack_a);
		else if (lst_len(*stack_a) == 3)
			sort_three(stack_a);
		else
			sort_many(stack_a, stack_b);
	}
	return (1);
}
