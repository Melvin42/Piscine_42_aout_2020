/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcols1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:33:45 by trouger           #+#    #+#             */
/*   Updated: 2020/08/16 20:55:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	two_one_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 2 && ins[0][x] == 1)
	{
		if (sol[1][x] == 3 || sol[2][x] == 3
				|| sol[1][x] == 4 || sol[2][x] == 4)
			return (0);
	}
	return (1);
}

int	three_one_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 3 && ins[1][x] == 1)
	{
		if (sol[0][x] == 3 || sol[0][x] == 4
				|| sol[2][x] == 3 || sol[2][x] == 4)
			return (0);
	}
	return (1);
}

int	one_three_col(int x, int sol[][4], int ins[][4])
{
	if (ins[0][x] == 1 && ins[1][x] == 3)
	{
		if (sol[1][x] == 4 || sol[1][x] == 3
				|| sol[3][x] == 3 || sol[3][x] == 4)
			return (0);
	}
	return (1);
}

int	checkcols(int x, int sol[][4], int ins[][4], int tower)
{
	if ((four_one_col(x, sol, ins, tower) == 0)
			|| (one_four_col(x, sol, ins, tower) == 0)
			|| (three_two_col(x, sol, ins) == 0)
			|| (two_three_col(x, sol, ins) == 0)
			|| (two_one_col(x, sol, ins) == 0)
			|| (one_two_col(x, sol, ins) == 0)
			|| (one_three_col(x, sol, ins) == 0)
			|| (three_one_col(x, sol, ins) == 0)
			|| (two_two_col(sol, ins) == 0))
		return (0);
	return (1);
}
