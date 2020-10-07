/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:24:56 by melperri          #+#    #+#             */
/*   Updated: 2020/08/26 15:56:00 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*extract_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(key = malloc(sizeof(*key) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*extract_word(char *str, int pos)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = pos;
	while (str[j] >= 32 && str[j] <= 126)
	{
		j++;
		i++;
	}
	if (!(word = malloc(sizeof(*word) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[pos] >= 32 && str[pos] <= 126)
	{
		word[i] = str[pos];
		i++;
		pos++;
	}
	word[i] = '\0';
	return (word);
}

void	extract_def(char *str, t_def *tab_def)
{
	int	i;

	i = 0;
	tab_def->key = extract_key(str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	tab_def->word = extract_word(str, i);
}

t_def	*create_tab_def(char **str)
{
	t_def	*tab_def;
	int		i;
	int		size;

	size = 0;
	while (str[size])
		size++;
	if (!(tab_def = malloc(sizeof(*tab_def) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < 41)
	{
		extract_def(str[i], &tab_def[i]);
		i++;
	}
	tab_def[i].key = 0;
	return (tab_def);
}

t_def	*create_tab_def_double(char **str)
{
	t_def	*tab_def;
	int		i;
	int		size;

	size = 0;
	while (str[size])
		size++;
	if (!(tab_def = malloc(sizeof(*tab_def) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		extract_def(str[i], &tab_def[i]);
		i++;
	}
	tab_def[i].key = 0;
	return (tab_def);
}
