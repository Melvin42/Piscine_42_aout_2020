/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcolerr1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 09:52:45 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 20:31:56 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		four_two_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 4 && ins[1][i] == 2)
			return (0);
		i++;
	}
	return (1);
}

int		two_four_col(int ins[][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 2 && ins[1][i] == 4)
			return (0);
		i++;
	}
	return (1);
}

int		ins_col_err(int ins[][4])
{
	if ((three_three_col(ins) == 0)
			|| (one_one_col(ins) == 0)
			|| (four_four_col(ins) == 0)
			|| (four_three_col(ins) == 0)
			|| (three_four_col(ins) == 0)
			|| (four_two_col(ins) == 0)
			|| (two_four_col(ins) == 0))
		return (0);
	return (1);
}
