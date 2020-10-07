/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:05:41 by melperri          #+#    #+#             */
/*   Updated: 2020/08/17 17:58:17 by melperri         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
