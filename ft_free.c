/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:08 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:24:09 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **av, t_list *head, int arg_size, int cont)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (av)
	{
		if (cont == 0)
		{
			while (i < arg_size)
				free(av[i++]);
			free(av);
		}
	}
	i = 0;
	if (head)
	{
		while (i++ < (arg_size))
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}
