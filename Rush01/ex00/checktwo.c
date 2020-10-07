/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:48:18 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 20:57:05 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		two_two_col(int sol[][4], int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 2 && ins[1][i] == 2)
		{
			if (sol[0][i] == 4 || sol[3][i] == 4)
				return (0);
		}
		i++;
	}
	return (1);
}

int		two_two_row(int sol[][4], int ins[][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ins[2][i] == 2 && ins[3][i] == 2)
		{
			if (sol[i][0] == 4 || sol[i][3] == 4)
				return (0);
		}
		i++;
	}
	return (1);
}
