/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 09:18:26 by cmarien           #+#    #+#             */
/*   Updated: 2020/08/09 11:21:41 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_rush_mid(long long ligne, long long colonne)
{
	char		a;
	char		b;
	long long	col_fixe;

	a = 'o';
	b = '|';
	while (ligne-- > 2)
	{
		col_fixe = colonne - 1;
		ft_putchar(b);
		while (col_fixe-- > 1 && col_fixe < colonne)
			ft_putchar(' ');
		ft_putchar(b);
		ft_putchar('\n');
	}
	ft_putchar(a);
}

void	ft_rush_1_colonne(long long ligne, char b, char a)
{
	ft_putchar('\n');
	while (ligne-- > 2)
	{
		ft_putchar(b);
		ft_putchar('\n');
	}
	ft_putchar(a);
	ft_putchar('\n');
}

void	ft_rush_ligne(long long colonne, char b, char c)
{
	while (colonne-- > 2)
		ft_putchar(b);
	ft_putchar(c);
	ft_putchar('\n');
}

void	rush(long long x, long long y)
{
	char a;
	char b;
	char c;

	a = 'o';
	b = '-';
	c = '|';
	if (y > 0 && x > 0)
	{
		ft_putchar(a);
		if (y == 1 && x == 1)
			ft_putchar('\n');
		else if (y == 1)
			ft_rush_ligne(x, b, a);
		else if (x == 1)
			ft_rush_1_colonne(y, c, a);
		else
		{
			ft_rush_ligne(x, b, a);
			ft_rush_mid(y, x);
			ft_rush_ligne(x, b, a);
		}
	}
}
