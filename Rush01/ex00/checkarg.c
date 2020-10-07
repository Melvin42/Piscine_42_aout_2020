/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:51:30 by trouger           #+#    #+#             */
/*   Updated: 2020/08/16 20:28:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		checkarg1(int argc, char *str)
{
	if (argc != 2)
	{
		return (0);
	}
	if (ft_strlen(str) != 31)
	{
		return (0);
	}
	return (1);
}

int		checkarg(char *str)
{
	int i;

	i = 0;
	if (str[i] >= '1' && str[i] <= '4')
		i += 2;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4') && str[i - 1] == ' ')
		{
			return (0);
		}
		if (str[i + 1] == '\0')
			return (1);
		i += 2;
	}
	return (1);
}

int		checkerror(int argc, char *str)
{
	if (checkarg1(argc, str) == 0)
		return (0);
	if (checkarg(str) == 0)
		return (0);
	return (1);
}
