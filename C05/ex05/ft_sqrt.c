/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:17:58 by melperri          #+#    #+#             */
/*   Updated: 2020/08/17 17:57:12 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 0;
	if (nb <= 0)
		return (0);
	else
		while (nb >= sqrt * sqrt && sqrt < 46341)
		{
			if (nb == sqrt * sqrt)
				return (sqrt);
			sqrt++;
		}
	return (0);
}
