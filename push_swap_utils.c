#include "push_swap.h"

long    ft_atol(char *av)
{
    int     i;
    long    res;
    long    sign;

    i = 0;
    res = 0;
    sign = 1;
    if (av[i] == '-' || av[i] == '+')
    {
        if (av[i] == '-')
            sign = -1;
        i++;
    }
    while (av[i] >= '0' && av[i] <= '9')
    {
        res = res * 10 + (av[i] - 48);
        i++;
    }
    return(res*sign);
}