/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:13 by melperri          #+#    #+#             */
/*   Updated: 2020/08/11 22:04:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			checkbase(char *base)
{
	int	i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			checksign(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	long long	nb;

	nb = nbr;
	if (ft_strlen(base) > 1 && checkbase(base) && checksign(base))
	{
		if (nb < 0)
		{
			nb = (nb * -1);
			write(1, "-", 1);
		}
		if (nb >= ft_strlen(base))
			ft_putnbr_base((nb / ft_strlen(base)), base);
		write(1, &base[nb % ft_strlen(base)], 1);
	}
}
