/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:53:06 by melperri          #+#    #+#             */
/*   Updated: 2020/08/26 15:24:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*skip_zero(char *num)
{
	int i;

	i = 0;
	while (num[i] == '0' && i < ft_strlen(num) - 1)
		i++;
	return (num + i);
}

int		check_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if ((!(str[i] >= '0' && str[i] <= '9')) 
					|| ft_strlen(str) > 37)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char *dd_dict, char *de_dict)
{
	free(dd_dict);
	free(de_dict);
}
