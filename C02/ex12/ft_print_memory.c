/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:17:25 by melperri          #+#    #+#             */
/*   Updated: 2020/08/09 16:40:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printhex(int nb, unsigned int i, unsigned int size)
{
	char *base;

	base = "0123456789abcdef";
	if (i <= size)
	{
		if (nb >= 0)
		{
			write(1, &base[nb / 16], 1);
			write(1, &base[nb % 16], 1);
		}
	}
	if ((i % 2 != 0 && i < size) || nb == 0)
		write(1, " ", 1);
}

void	printaddr(unsigned long addr)
{
	int		i;
	char	tab[17];
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		tab[15 - i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	tab[16] = '\0';
	i = 0;
	while (i < 16)
	{
		write(1, &tab[i], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	ft_putstr_non_printable(char c)
{
	if (c != 0)
	{
		if (c >= ' ' && c <= '~')
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	ij[2];
	int				line;

	ij[0] = 0;
	ij[1] = 0;
	while (ij[0] < size)
	{
		line = -1;
		printaddr((unsigned long)addr + ij[0]);
		while (line++ < 32)
		{
			if (line < 16)
			{
				printhex(((char *)addr)[ij[0]], ij[0], size);
				ij[0]++;
			}
			else if (line < 32)
				ft_putstr_non_printable(((char *)addr)[ij[1]++]);
		}
		if (ij[0] < size)
			write(1, "\n", 1);
	}
	write(1, ".\n", 2);
	addr = &((char *)addr)[0];
	return (addr);
}
