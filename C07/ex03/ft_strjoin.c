/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:46:48 by melperri          #+#    #+#             */
/*   Updated: 2020/08/14 11:25:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy_plus(char *join, char **strs, char *sep, int size)
{
	int	i[2];
	int cpy;

	i[0] = 0;
	i[1] = 0;
	while (i[0] < size)
	{
		cpy = 0;
		while (strs[i[0]][cpy])
		{
			join[i[1]] = strs[i[0]][cpy];
			i[1]++;
			cpy++;
		}
		cpy = 0;
		while (sep[cpy] && i[0] < size - 1)
		{
			join[i[1]] = sep[cpy];
			i[1]++;
			cpy++;
		}
		i[0]++;
	}
	join[i[1]] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		fullsize;
	int		i;

	join = NULL;
	fullsize = 0;
	i = 0;
	while (i < size)
	{
		fullsize = fullsize + ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	if (!(join = (char *)malloc(sizeof(char) * fullsize + 1)))
		return (NULL);
	ft_strcpy_plus(join, strs, sep, size);
	return (join);
}
