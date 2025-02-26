#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


int    ft_push_swap(char **av)
{
    long    number;
    int     i;
    t_list  *head;

    head = NULL;
    i = 0;
    number = 0;
    while (av[i])
    {
        number = ft_atol(av[i]);
        if (number > 2147483647  || number < -2147483648 )
            return (0);
        if (!add_to_list(number, &head))
            return (0);
        i++;
    }
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
   return (1); 
}

int ft_control_args(char *av)
{
    int i;

    i = 0;
    if ((av[0] > '9' || av[0] < '0') && (av[0] != '+' && av[0] != '-'))
        return (0);
    while (av[i])// "1 2 --233 12"
    {
        if ((av[i] > '0' && av[i] < '9') && !(av[i + 1] == '-' || av[i + 1] == '+'))
            i++;
        else if ((av[i] == '-' || av[i] == '+') && !(av[i + 1] == '-' || av[i + 1] == '+') 
            && (av[i + 1] > '0' && av[i + 1] < '9'))
            i++;
        else if (av[i] == ' ' && (av[i + 1] <= '9' && av[i + 1] >= '0'))
            i++;
        else if (av[i] == ' ' && (av[i + 1] == '+' || av[i + 1] == '-'))
            i++;
        else 
            return (0);
    }
    return (1);
}

int ft_control(char **av)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (av[i])
    {
        if (!ft_control_args(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char** av)
{
    char **data;

    data = NULL;
    if (ac == 1)
        return (0);
    else
    {
        if (ft_control(av + 1) == 0)
        {
            write(1,"Error\n", 6);
            return (0);
        }
    }
    if (ac == 2)
    {
        data = ft_split(av[1], ' ');
        if (data)
            ft_push_swap(data);
    }
    else   
        ft_push_swap(av + 1);
    return (0);
}
