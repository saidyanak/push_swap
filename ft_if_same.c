/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_same.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:06 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:24:06 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_same(t_list *head)
{
	t_list		*last;
	static int	j = 0;
	int			i;
	int arg_size;

	arg_size = lst_len(head);
	i = 0;
	if (arg_size < 2)
		return (0);
	last = head->next;
	while (i < (arg_size - 1))
	{
		if (head->data == last->data)
		{
			return (ft_free(NULL, head, arg_size, 0), exit(1), 1);
		}
		last = last->next;
		i++;
	}
	j++;
	if (j == (arg_size - 1))
		return (0);
	return (ft_if_same(head->next));
}
