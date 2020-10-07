/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:17:17 by melperri          #+#    #+#             */
/*   Updated: 2020/08/09 19:58:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printhex(int nb)
{
	char *str;

	str = "0123456789abcdef";
	write(1, &str[nb / 16], 1);
	write(1, &str[nb % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_printhex(str[i]);
		}
		i++;
	}
}
