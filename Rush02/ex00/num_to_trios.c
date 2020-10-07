/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_trios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:50:39 by melperri          #+#    #+#             */
/*   Updated: 2020/08/23 21:02:02 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_last_trio(char **trios, char *num, int j, int *index_trio)
{
	if (j != 3)
	{
		if (!(trios[*index_trio] = malloc(sizeof(char) * 4)))
			return (0);
		if (j == 2)
		{
			trios[*index_trio][2] = num[1];
			trios[*index_trio][1] = num[0];
			trios[*index_trio][0] = '0';
		}
		if (j == 1)
		{
			trios[*index_trio][2] = num[0];
			trios[*index_trio][1] = '0';
			trios[*index_trio][0] = '0';
		}
		trios[*index_trio][3] = '\0';
	}
	if (ft_strlen(num) % 3 != 0)
		*index_trio += 1;
	trios[*index_trio] = NULL;
	return (1);
}

char	**to_trios(char *num)
{
	int		i;
	int		j;
	int		index_trio;
	char	**trios;

	i = ft_strlen(num);
	j = 0;
	index_trio = 0;
	if (!(trios = malloc(sizeof(*trios) * (i / 3 + !(i % 3 == 0) + 1))))
		return (NULL);
	while (i-- > 0)
	{
		if (++j == 3)
		{
			if (!(trios[index_trio] = malloc(sizeof(char) * 3)))
				return (NULL);
			while (--j >= 0)
				trios[index_trio][j] = num[i + j];
			j = 0;
			index_trio++;
		}
		if (!i && !get_last_trio(trios, num, j, &index_trio))
			return (NULL);
	}
	return (trios);
}
