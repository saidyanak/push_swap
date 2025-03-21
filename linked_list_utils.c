/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:55 by syanak            #+#    #+#             */
/*   Updated: 2025/03/21 01:19:01 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*last_node(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

t_list	*second_last_node(t_list *head)
{
	t_list	*tmp;

	if (lst_len(head) == 2)
		return (head->next);
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->next == head)
			return (tmp);
	}
	return (head);
}

int	lst_len(t_list *list)
{
	int		len;
	t_list	*head;

	len = 0;
	head = list;
	while (head->next != list)
	{
		head = head->next;
		len++;
	}
	return (len + 1);
}

int	add_to_list(long number, t_list **head, int i)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = NULL;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = number;
	new_node->next = NULL;
	if (!(*head))
		*head = new_node;
	else
	{
		if (i < 2)
		{
			tmp = last_node(*head);
		}
		else
			tmp = second_last_node(*head);
		tmp->next = new_node;
		new_node->next = *head;
	}
	return (1);


}

int	is_sorted(t_list *lst)
{
	int		i;
	t_list	*head;

	head = lst;
	i = 0;
	if (lst->next == NULL)
		return (0);
	while (head != lst->next)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}
