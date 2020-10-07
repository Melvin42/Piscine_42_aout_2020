/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:31:28 by trouger           #+#    #+#             */
/*   Updated: 2020/08/16 20:55:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	four_one_col(int x, int sol[][4], int ins[][4], int tower)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][x] == 4 && ins[1][x] == 1)
		{
			if (sol[i][x] >= tower)
				return (0);
		}
		i++;
	}
	return (1);
}

int	one_four_col(int x, int sol[][4], int ins[][4], int tower)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][x] == 1 && ins[1][x] == 4)
		{
			if (sol[i][x] <= tower)
				return (0);
		}
		i++;
	}
	return (1);
}

int	two_three_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 2 && ins[1][x] == 3)
	{
		if (sol[0][x] == 4 || sol[2][x] == 4 || sol[3][x] == 4)
			return (0);
	}
	return (1);
}

int	three_two_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 3 && ins[1][x] == 2)
	{
		if (sol[0][x] == 4 || sol[1][x] == 4 || sol[3][x] == 4)
			return (0);
	}
	return (1);
}

int	one_two_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 1 && ins[1][x] == 2)
	{
		if (sol[1][x] == 3 || sol[1][x] == 4
			|| sol[2][x] == 3 || sol[2][x] == 4)
			return (0);
	}
	return (1);
}
