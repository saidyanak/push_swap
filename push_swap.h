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

long				ft_atol(char *av);

char				**ft_split(char *s, char c);
char				*push(t_list **stack_a, t_list **stack_b, char *strig);

void				actions(t_list **stack_a, t_list **stack_b, char *action);
void				set_index(t_list *stack);
void    			set_top_node(t_list **lst, t_list *current, char stack);
void				sort_two(t_list **stack_a);
void				sort_three(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_many(t_list **stack_a, t_list **stack_b);

int 				ft_strlen(char *str);
int					ft_control(char **av);
int					ft_lst_strlen(char **av);
int					ft_if_same(t_list *head);
int					sort(t_list **stack_a, t_list **stack_b);
int					is_sorted(t_list *lst);
int					lst_len(t_list *list);
int					is_sorted(t_list *lst);
int					add_to_list(long number, t_list **head, int i);

t_list				*find_min(t_list *stack);
t_list				*find_max(t_list *stack);
t_list				*get_cheapest(t_list *stack);
t_list				*second_last_node(t_list *head);
t_list				*create_list(int ac, char **av);

void 				error(int ac, char **av);
void				ft_free(char **av, t_list *head, int arg_size, int cont);
void    			move_stack_a(t_list **stack_a, t_list **stack_b);
void				move_stack_b(t_list **stack_a, t_list **stack_b);
void    			move_a_to_b(t_list **stack_a, t_list **stack_b);

#endif
