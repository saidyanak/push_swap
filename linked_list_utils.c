#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_list  *last_node(t_list *lst)
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

int add_to_list(long number, t_list **head)
{
    t_list *new_node;
    t_list *tmp;

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
        tmp = last_node(*head);
        tmp->next = new_node;
        new_node->next = *head;
    }
    return (1);
}