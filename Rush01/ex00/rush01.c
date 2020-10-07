/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:57:15 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 23:21:35 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		checkdouble(int x, int y, int sol[][4], int tower)
{
	int i;

	i = 0;
	while (i <= x)
	{
		if (sol[y][i] == tower)
			return (0);
		i++;
	}
	i = 0;
	while (i <= y)
	{
		if (sol[i][x] == tower)
			return (0);
		i++;
	}
	return (1);
}

void	backtrack(int x, int y, int sol[][4], int ins[][4], int *fin)
{
	int	twr;

	if (y > 3 && *fin == 0)
	{
		printtab(sol);
		*fin = 1;
	}
	else
	{
		twr = 0;
		while (++twr <= 4)
		{
			if ((checkdouble(x, y, sol, twr)) && (checkrows(y, sol, ins, twr))
					&& (checkcols(x, sol, ins, twr)))
			{
				sol[y][x] = twr;
				if (x == 3)
					backtrack(0, y + 1, sol, ins, fin);
				else
					backtrack(x + 1, y, sol, ins, fin);
			}
			sol[y][x] = 0;
		}
	}
}

void	fill_tab(char *str, int ins[][4])
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			ins[y][x] = ft_atoi(&str[i]);
			if (x < 3)
				x++;
			else
			{
				x = 0;
				y = y + 1;
			}
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	sol[4][4];
	int ins[4][4];
	int i;
	int fin;

	fin = 0;
	if (!(checkerror(argc, argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		zero(i, sol);
		i++;
	}
	fill_tab(argv[1], ins);
	backtrack(0, 0, sol, ins, &fin);
	if (fin == 0)
		write(1, "Error\n", 6);
	return (0);
}
