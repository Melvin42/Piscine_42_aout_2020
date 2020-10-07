/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:51:15 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 22:19:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdoop.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int		ft_atoi(char *str)
{
	int i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int		checkerror(char **av)
{
	if (ft_strlen(av[2]) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (av[2][0] == '/' && ft_atoi(av[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (!(av[2][0] == '+' || av[2][0] == '-' || av[2][0] == '/'
				|| av[2][0] == '*' || av[2][0] == '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}
