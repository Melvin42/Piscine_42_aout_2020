/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:07:02 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 14:18:06 by melperri         ###   ########.fr       */
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

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	if (charset[0] == '\0')
		return (1);
	while (ischarset(str[i], charset))
		i++;
	while (str[i])
	{
		while (!(ischarset(str[i], charset)))
			i++;
		count++;
		while (ischarset(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int wordsize, int j)
{
	int	i;

	i = 0;
	while (src[j] && i < wordsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**dupword(char *str, char *charset, char **split, int wordsize)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (ischarset(str[i], charset))
		i++;
	while (str[i])
	{
		if (!(ischarset(str[i], charset)))
		{
			while (!(ischarset(str[i], charset)))
			{
				i++;
				wordsize++;
			}
			if (!(split[j] = malloc(sizeof(char) * (wordsize + 1))))
				return (NULL);
			split[j] = ft_strncpy(split[j], str, wordsize, (i - wordsize));
			j++;
			wordsize = 0;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		cmpt;
	int		i;

	cmpt = countword(str, charset);
	if (!(split = malloc(sizeof(char *) * (cmpt + 1))))
		return (NULL);
	i = 0;
	if (charset[0] == '\0')
	{
		while (str[i])
			i++;
		if (!(split[0] = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		split[0] = ft_strncpy(split[0], str, i, 0);
		split[cmpt] = 0;
		return (split);
	}
	split = dupword(str, charset, split, 0);
	split[cmpt] = 0;
	return (split);
}
