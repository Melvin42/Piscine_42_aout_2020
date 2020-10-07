/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:40:58 by melperri          #+#    #+#             */
/*   Updated: 2020/08/17 18:00:51 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	nbr;
	long	i;

	nbr = nb;
	i = 2;
	if (nbr < 2)
		return (0);
	else
		while (i < nbr && i * i <= nbr)
		{
			if (nbr % i == 0)
				return (0);
			i++;
		}
	return (1);
}
