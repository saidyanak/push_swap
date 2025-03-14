/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:52 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:54:43 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_control_args(char *av)
{
	int	i;

	i = 0;
	if ((av[0] > '9' || av[0] < '0') && (av[0] != '+' && av[0] != '-'))
		return (0);
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') && !(av[i + 1] == '-' || av[i
				+ 1] == '+'))
			i++;
		else if ((av[i] == '-' || av[i] == '+') && !(av[i + 1] == '-' || av[i
				+ 1] == '+') && (av[i + 1] >= '0' && av[i + 1] <= '9'))
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

int	ft_control(char **av)
{
	int	i;
	int	k;

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

int	ft_lst_strlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
