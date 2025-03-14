/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:33 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:24:26 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	error(ac,av);
	stack_b = NULL;
	stack_a = create_list(ac, av);
	ft_if_same(stack_a);
	sort(&stack_a, &stack_b);
	ft_free(NULL, stack_a, lst_len(stack_a), 0);
	return (0);
}
