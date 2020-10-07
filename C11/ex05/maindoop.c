/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:55:19 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 22:06:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdoop.h"

int		ft_calcul(int a, int b, int (*f)(int, int))
{
	int	res;

	res = (*f)(a, b);
	return (res);
}

int		main(int ac, char **av)
{
	int	res;

	res = 0;
	if (ac != 4)
		return (0);
	if (!(checkerror(av)))
		return (0);
	if (av[2][0] == '+')
		res = ft_calcul(ft_atoi(av[1]), ft_atoi(av[3]), &ft_add);
	if (av[2][0] == '-')
		res = ft_calcul(ft_atoi(av[1]), ft_atoi(av[3]), &ft_sub);
	if (av[2][0] == '*')
		res = ft_calcul(ft_atoi(av[1]), ft_atoi(av[3]), &ft_mul);
	if (av[2][0] == '/')
		res = ft_calcul(ft_atoi(av[1]), ft_atoi(av[3]), &ft_div);
	if (av[2][0] == '%')
		res = ft_calcul(ft_atoi(av[1]), ft_atoi(av[3]), &ft_mod);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
