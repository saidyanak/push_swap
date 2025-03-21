/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:44 by syanak            #+#    #+#             */
/*   Updated: 2025/03/21 03:24:54 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_list **stack_a, t_list **stack_b)
{
	int i = 0;
	if (!is_sorted(*stack_a))
	{
		if (lst_len(*stack_a) == 1)
			return (0);
		else if (lst_len(*stack_a) == 2)
			sort_two(stack_a);
		else if (lst_len(*stack_a) == 3)
			sort_three(stack_a);
		else if (lst_len(*stack_a) == 4)
			sort_four(stack_a, stack_b);
		else
			sort_many(stack_a, stack_b);
	}
	return (1);
}
