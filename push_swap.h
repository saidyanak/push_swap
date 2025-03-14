/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:47 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:54:55 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

int					add_to_list(long number, t_list **head, int i);
long				ft_atol(char *av);
int					sort(t_list **stack_a, t_list **stack_b);
char				**ft_split(char *s, char c);
int	is_sorted(t_list *lst);
int	lst_len(t_list *list);
void	actions(t_list **stack_a, t_list **stack_b, char *action);
t_list	*second_last_node(t_list *head);
int	is_sorted(t_list *lst);
int	ft_control(char **av);
int	ft_lst_strlen(char **av);
void error(int ac, char **av);
t_list	*create_list(int ac, char **av);
void	ft_free(char **av, t_list *head, int arg_size, int cont);
int	ft_if_same(t_list *head);
int ft_strlen(char *str);

#endif
