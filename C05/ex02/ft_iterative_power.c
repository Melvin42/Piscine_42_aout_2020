/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:20:58 by melperri          #+#    #+#             */
/*   Updated: 2020/08/17 21:31:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	if (power < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (power >= 1)
	{
		while (power >= 1)
		{
			res = res * nb;
			power--;
		}
	}
	return (res);
}
