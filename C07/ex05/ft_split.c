/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:22:48 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 11:12:28 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ischarset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		countword(char *str, char *charset)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (ischarset(str[i], charset) && (!(ischarset(str[i - 1], charset))))
			count++;
		i++;
	}
	if (str[i] == '\0' && (!(ischarset(str[i - 1], charset))))
		count++;
	return (count);
}

char	**mallocword(char *str, char *charset, char **split)
{
	int	i;
	int j;
	int wordsize;

	i = 0;
	j = 0;
	wordsize = 1;
	if (str[i] == '\0')
		return (split);
	while (str[i])
	{
		while (ischarset(str[i], charset))
			i++;
		if (ischarset(str[i + 1], charset) || str[i + 1] == '\0')
		{
			if (!(split[j] = (char *)malloc(sizeof(char) * wordsize + 1)))
				return (NULL);
			j++;
			wordsize = 0;
		}
		wordsize++;
		i++;
	}
	return (split);
}

char	**filltab(char *str, char *charset, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (ischarset(str[i], charset))
			i++;
		split[j][k] = str[i];
		k++;
		if (ischarset(str[i + 1], charset) || str[i + 1] == '\0')
		{
			split[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		cmpt;

	cmpt = countword(str, charset);
	if (!(split = malloc(sizeof(char *) * (cmpt + 1))))
		return (NULL);
	split = mallocword(str, charset, split);
	split = filltab(str, charset, split);
	split[cmpt] = 0;
	return (split);
}
