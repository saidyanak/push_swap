#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}t_list;

int add_to_list(long number, t_list **head);
long    ft_atol(char *av);
char	**ft_split(char *s, char c);

# endif