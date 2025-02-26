#include <stddef.h>
#include <unistd.h>

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
        }
    }
}
