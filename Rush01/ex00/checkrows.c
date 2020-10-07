/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:56:31 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 20:58:43 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	four_one_row(int y, int sol[][4], int ins[][4], int tower)
{
	int i;

	i = 0;
	if (ins[2][y] == 4 && ins[3][y] == 1)
	{
		while (i < 4)
		{
			if (sol[y][i] >= tower)
				return (0);
			i++;
		}
	}
	return (1);
}

int	one_four_row(int y, int sol[][4], int ins[][4], int tower)
{
	int i;

	i = 0;
	if (ins[2][y] == 1 && ins[3][y] == 4)
	{
		while (i < 4)
		{
			if (sol[y][i] <= tower)
				return (0);
			i++;
		}
	}
	return (1);
}

int	two_three_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 2 && ins[3][y] == 3)
	{
		if (sol[y][0] == 4 || sol[y][2] == 4 || sol[y][3] == 4)
			return (0);
	}
	return (1);
}

int	three_two_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 3 && ins[3][y] == 2)
	{
		if (sol[y][0] == 4 || sol[y][1] == 4 || sol[y][3] == 4)
			return (0);
	}
	return (1);
}

int	one_two_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 1 && ins[3][y] == 2)
	{
		if (sol[y][3] == 3 || sol[y][0] == 4)
			return (1);
		if (sol[y][0] == 3 || sol[y][1] == 4
				|| sol[y][1] == 3 || sol[y][2] == 4
				|| sol[y][2] == 3 || sol[y][3] == 4)
			return (0);
	}
	return (1);
}
