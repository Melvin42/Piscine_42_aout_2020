/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:12:50 by melperri          #+#    #+#             */
/*   Updated: 2020/08/23 22:13:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_next_opposite(char *str, char *sep)
{
	int		n;
	int		i;

	n = ft_is_sep(str[0], sep);
	i = 0;
	while (str[i])
	{
		if (n != ft_is_sep(str[i], sep))
			return (str + i);
		i++;
	}
	return (NULL);
}

int		ft_count_words(char *str, char *sep)
{
	int		words;
	char	*buff;

	words = 0;
	if (str != NULL)
	{
		buff = str;
		while (buff != NULL)
		{
			if (!ft_is_sep(buff[0], sep))
				words++;
			buff = ft_next_opposite(buff, sep);
		}
	}
	return (words);
}

char	**ft_split_string(char *str, char *charset)
{
	char	**slots;
	int		words;
	int		i;
	int		index_mot;

	words = ft_count_words(str, charset);
	if (!(slots = malloc(sizeof(char	*) * (words + 1))))
		return (NULL);
	slots[words] = NULL;
	index_mot = -1;
	while (++index_mot < words)
	{
		if (ft_is_sep(str[0], charset))
			str = ft_next_opposite(str, charset);
		i = 0;
		while (str[i] && !ft_is_sep(str[i], charset))
			i++;
		if (!(slots[index_mot] = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		slots[index_mot][i] = '\0';
		while (--i >= 0)
			slots[index_mot][i] = str[i];
		str = ft_next_opposite(str, charset);
	}
	return (slots);
}
