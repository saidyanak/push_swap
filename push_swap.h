/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:47 by syanak            #+#    #+#             */
/*   Updated: 2025/03/20 22:17:52 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
	int				data;
	int				median;
	int				index;
	int				cost;
	int				cheapest;
	struct s_list	*taget;
	struct s_list	*next;
}					t_list;

int					add_to_list(long number, t_list **head, int i);
long				ft_atol(char *av);
int					sort(t_list **stack_a, t_list **stack_b);
char				**ft_split(char *s, char c);
int	is_sorted(t_list *lst);
int	lst_len(t_list *list);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
void	actions(t_list **stack_a, t_list **stack_b, char *action);
void	set_index(t_list *stack);
void    move_stack_a(t_list **stack_a, t_list **stack_b);
void    move_a_to_b(t_list **stack_a, t_list **stack_b);
void    set_top_node(t_list **lst, t_list *current, char stack);
t_list	*second_last_node(t_list *head);
int	is_sorted(t_list *lst);
int	ft_control(char **av);
int	ft_lst_strlen(char **av);
void error(int ac, char **av);
t_list	*create_list(int ac, char **av);
void	ft_free(char **av, t_list *head, int arg_size, int cont);
int	ft_if_same(t_list *head);
int ft_strlen(char *str);
char	*push(t_list **stack_a, t_list **stack_b, char *strig);
void	find_chepest_push(t_list **stack_a, t_list **stack_b);

#endif
