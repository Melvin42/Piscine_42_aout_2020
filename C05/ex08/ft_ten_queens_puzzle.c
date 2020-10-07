/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 08:36:55 by melperri          #+#    #+#             */
/*   Updated: 2020/08/17 21:15:32 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	zero(int y, int board[][10])
{
	int x;

	x = 0;
	while (x < 10)
	{
		board[y][x] = 0;
		x++;
	}
}

int		check(int x, int y, int board[][10])
{
	int y_pos;
	int x_pos;

	y_pos = 0;
	while (y_pos < 10)
	{
		x_pos = 0;
		while (x_pos < 10)
		{
			if (x == x_pos || y == y_pos
					|| (x_pos - x) == (y_pos - y)
					|| (x_pos - x) == (y - y_pos))
				if (board[y_pos][x_pos] == 1)
				{
					return (0);
				}
			x_pos++;
		}
		y_pos++;
	}
	return (1);
}

void	printtab(int board[][10])
{
	int		x;
	int		y;
	char	*base;

	base = "0123456789";
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (board[y][x] == 1)
				write(1, &base[x], 1);
			x++;
		}
		y++;
	}
	write(1, "\n", 1);
}

void	backtrack(int x, int board[][10], int *cmpt)
{
	int y;

	if (x > 9)
	{
		*cmpt += 1;
		printtab(board);
	}
	y = 0;
	while (y < 10)
	{
		if (check(x, y, board))
		{
			board[y][x] = 1;
			backtrack(x + 1, board, cmpt);
			board[y][x] = 0;
		}
		y++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int board[10][10];
	int cmpt;

	cmpt = 0;
	while (cmpt < 10)
	{
		zero(cmpt, board);
		cmpt++;
	}
	cmpt = 0;
	backtrack(0, board, &cmpt);
	return (cmpt);
}
