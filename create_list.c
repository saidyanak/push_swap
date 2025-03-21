/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:13 by syanak            #+#    #+#             */
/*   Updated: 2025/03/21 02:33:15 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_zero(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while (head)
	{
		head->cheapest = 0;
		head->cost		= 0;
		head->index		= 0;
		head->median	=0;
		head->taget		=NULL;
		head = head->next;
		if (tmp == head)
			break;	
	}
}

t_list	*create_linked_list(char **av, int cont)
{
	long	number;
	int		i;
	int		argsize;
	t_list	*head;

	argsize = ft_lst_strlen(av);
	head = NULL;
	i = 0;
	number = 0;
	if (argsize == 1)
		return (ft_free(av, NULL, argsize, cont), exit(1), NULL);
	while (av[i])
	{
		number = ft_atol(av[i]);
		if (number > 2147483647 || number < -2147483648)
			return (ft_free(av, head, argsize, cont), NULL);
		if (!add_to_list(number, &head, i))
			return (ft_free(av, head, argsize, cont), NULL);
		i++;
	}
	return (head);
}

t_list	*ft_push_swap(char **av, int cont)
{
	t_list	*stack_a;

	stack_a = create_linked_list(av, cont);
	if (!stack_a)
		return (NULL);
	if ((is_sorted(stack_a)))
		return (ft_free(av, stack_a, ft_lst_strlen(av), cont), exit(1), NULL);
	return (stack_a);
}

t_list	*create_list(int ac, char **av)
{
	t_list	*head;
	char	**data;

	data = NULL;
	if (ac == 2)
	{
		data = ft_split(av[1], ' ');
		if (data)
			head = ft_push_swap(data, 0);
		ft_free(data, NULL, ft_lst_strlen(data), 0);
	}
	else
		head = ft_push_swap(av + 1, 1);
	ft_zero(head);
	return (head);
}
