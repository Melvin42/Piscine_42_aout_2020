/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcolerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 09:25:49 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 20:31:02 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		three_three_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 3 && ins[1][i] == 3)
			return (0);
		i++;
	}
	return (1);
}

int		one_one_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 1 && ins[1][i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int		four_four_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 4 && ins[1][i] == 4)
			return (0);
		i++;
	}
	return (1);
}

int		four_three_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 4 && ins[1][i] == 3)
			return (0);
		i++;
	}
	return (1);
}

int		three_four_col(int ins[][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ins[0][i] == 3 && ins[1][i] == 4)
			return (0);
		i++;
	}
	return (1);
}
