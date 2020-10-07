/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrows1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:59:01 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 20:57:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	two_one_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 2 && ins[3][y] == 1)
	{
		if (sol[y][1] == 3 || sol[y][2] == 3
				|| sol[y][1] == 4 || sol[y][2] == 4)
			return (0);
	}
	return (1);
}

int	one_three_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 1 && ins[3][y] == 3)
	{
		if (sol[y][1] == 4 || sol[y][1] == 3
				|| sol[y][3] == 3 || sol[y][3] == 4)
			return (0);
	}
	return (1);
}

int	three_one_row(int y, int sol[][4], int ins[][4])
{
	if (ins[2][y] == 3 && ins[3][y] == 1)
	{
		if (sol[y][0] == 3 || sol[y][0] == 4
			|| sol[y][2] == 3 || sol[y][2] == 4)
			return (0);
	}
	return (1);
}

int	checkrows(int y, int sol[][4], int ins[][4], int tower)
{
	if ((four_one_row(y, sol, ins, tower) == 0)
			|| (one_four_row(y, sol, ins, tower) == 0)
			|| (three_two_row(y, sol, ins) == 0)
			|| (two_three_row(y, sol, ins) == 0)
			|| (two_one_row(y, sol, ins) == 0)
			|| (one_two_row(y, sol, ins) == 0)
			|| (one_three_row(y, sol, ins) == 0)
			|| (three_one_row(y, sol, ins) == 0)
			|| (two_two_row(sol, ins) == 0))
		return (0);
	return (1);
}
