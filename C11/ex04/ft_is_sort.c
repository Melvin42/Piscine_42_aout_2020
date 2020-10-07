/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:21:48 by melperri          #+#    #+#             */
/*   Updated: 2020/08/25 19:00:27 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	if (length <= 1)
		return (1);
	while (tab[i] == tab[i + 1] && i < length - 1)
		i++;
	if (tab[i] < tab[i + 1] && i < length - 1)
	{
		i = -1;
		while (++i < length - 1)
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
	}
	else if (tab[i] > tab[i + 1] && i < length - 1)
	{
		i = -1;
		while (++i < length - 1)
			if ((*f)(tab[i], tab[i + 1]) < 0)
				return (0);
	}
	return (1);
}
