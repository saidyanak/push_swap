/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:11 by syanak            #+#    #+#             */
/*   Updated: 2025/03/14 12:24:11 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void error(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	else
	{
		if (ft_control(av + 1) == 0)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}
