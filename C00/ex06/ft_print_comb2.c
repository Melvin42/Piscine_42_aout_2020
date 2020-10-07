/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:08:08 by melperri          #+#    #+#             */
/*   Updated: 2020/08/07 09:53:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar6(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int one;
	int two;

	one = 0;
	two = 0;
	while (one <= 98)
	{
		two = one + 1;
		while (two <= 99)
		{
			ft_putchar6(one / 10 + '0');
			ft_putchar6(one % 10 + '0');
			ft_putchar6(' ');
			ft_putchar6(two / 10 + '0');
			ft_putchar6(two % 10 + '0');
			if (!(one == 98))
			{
				ft_putchar6(',');
				ft_putchar6(' ');
			}
			two++;
		}
		one++;
	}
}
