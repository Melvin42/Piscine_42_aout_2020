/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 08:46:10 by melperri          #+#    #+#             */
/*   Updated: 2020/08/07 09:53:24 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar5(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int one;
	int two;
	int three;

	one = 0;
	two = 1;
	while (one <= 7)
	{
		two = one + 1;
		while (two <= 8)
		{
			three = two + 1;
			while (three <= 9)
			{
				ft_putchar5(one + '0');
				ft_putchar5(two + '0');
				ft_putchar5(three + '0');
				if (one != 7)
					write(1, ", ", 2);
				three++;
			}
			two++;
		}
		one++;
	}
}
