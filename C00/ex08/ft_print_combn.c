/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:45:32 by melperri          #+#    #+#             */
/*   Updated: 2020/08/07 10:45:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printtab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_settab(int *tab, int n)
{
	int i;

	i = 0;
	tab[0] = 0;
	while (i < n)
	{
		tab[i + 1] = tab[i] + 1;
		i++;
	}
}

int		ft_checktab(int *tab, int n)
{
	int i;
	int cres;

	i = 1;
	cres = 0;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i])
			cres = 1;
		i++;
	}
	if (cres == 0)
		ft_printtab(tab, n);
	return (cres);
}

void	ft_print_combn(int n)
{
	int tab[n];
	int i;

	i = 0;
	if (n < 1 || n > 9)
		return ;
	ft_settab(tab, n);
	while (tab[0] <= (10 - n))
	{
		if (ft_checktab(tab, n) == 0)
			if (!(tab[0] == (10 - n)))
				write(1, ", ", 2);
		while (i < n)
		{
			if (tab[i] >= 9 && n > 1)
			{
				tab[i] = 0;
				tab[i - 1]++;
			}
			if (i == n - 1)
				tab[i]++;
			i++;
		}
		i = 0;
	}
}
