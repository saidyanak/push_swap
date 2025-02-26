#include <stdio.h>

long int    ft_atol(char *av)
{
    long int    i;
    long int    res;
    long int    sign;

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

int main()
{
    printf("%d\n", ft_atol("12"));
}