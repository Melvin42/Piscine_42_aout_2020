/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:38:06 by melperri          #+#    #+#             */
/*   Updated: 2020/08/23 15:38:56 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		separator_check(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

char	*ft_dupsplit(char *src, char charset)
{
	char	*p;
	int		i;

	i = 0;
	while (src[i] && !separator_check(src[i], charset))
		i++;
	if (!(p = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] && !separator_check(src[i], charset))
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int		count_strings(char *str, char charset)
{
	int i;
	int strings_counter;

	i = 0;
	strings_counter = 0;
	while (str[i])
	{
		while (str[i] && separator_check(str[i], charset))
			i++;
		if (str[i] && !separator_check(str[i], charset))
		{
			strings_counter++;
			while (str[i] && !separator_check(str[i], charset))
				i++;
		}
	}
	return (strings_counter);
}

char	**ft_split(char *str)
{
	int		i;
	int		a;
	int		strings_counter;
	char	charset;
	char	**tab;

	i = 0;
	a = 0;
	charset = '\n';
	strings_counter = count_strings(str, charset);
	if (!(tab = (char **)malloc(sizeof(char*) * (strings_counter + 1))))
		return (NULL);
	while (*str)
	{
		while (*str && separator_check(*str, charset))
			str++;
		if (*str && !separator_check(*str, charset))
		{
			tab[a++] = ft_dupsplit(str, charset);
			while (*str && !separator_check(*str, charset))
				str++;
		}
	}
	tab[a] = 0;
	return (tab);
}
