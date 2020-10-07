/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:06:27 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 23:13:53 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	zero(int i, int tab[][4])
{
	int j;

	j = 0;
	while (j < 4)
	{
		tab[i][j] = 0;
		j++;
	}
}

void	printtab(int tab[][4])
{
	int	x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putnbr(tab[y][x]);
			if (x < 3)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
