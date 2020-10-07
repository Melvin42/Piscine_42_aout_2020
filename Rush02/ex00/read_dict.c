/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   godico.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:21:36 by melperri          #+#    #+#             */
/*   Updated: 2020/08/23 23:34:15 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			get_dict(char *dict, char **dest_dict)
{
	int		fd;
	int		ret;
	int		size;
	char	buf[BUF_SIZE + 1];

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (1);
	size = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		size = size + ret;
		buf[ret] = '\0';
	}
	if (close(fd) == -1)
		return (1);
	*dest_dict = ft_strdup(buf);
	return (size);
}

int			ft_strcmp_num(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && (s1[i] >= '0' && s1[i] <= '9')
			&& (s2[i] >= '0' && s2[i] <= '9'))
		i++;
	return (s1[i] - s2[i]);
}

int			check_def(char *str)
{
	int i;

	if (contains_only(str, ' '))
		return (1);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' && i != 0)
		i++;
	if (str[i] != ':' || i == 0)
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] < ' ') || (str[i] > '~'))
			return (0);
		i++;
	}
	return (1);
}

char		**get_rid_of_break_lines(char *str)
{
	char	**defs;
	int		i;
	int		j;

	i = 0;
	defs = ft_split_string(str, "\n");
	while (defs[i] != NULL)
	{
		if ((j = contains(defs[i], '\n')) != -1)
			str[j] = 0;
		i++;
	}
	return (defs);
}

int			dic_is_valid(char *str)
{
	char	**defs;
	int		j;
	int		i;
	int		*keys;

	i = 0;
	defs = get_rid_of_break_lines(str);
	if (!(keys = malloc(sizeof(int) * i)))
		return (0);
	i = 0;
	while (defs[i] != NULL)
	{
		if (!check_def(defs[i]))
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (!ft_strcmp_num(defs[i], defs[j]))
				return (0);
			j--;
		}
		i++;
	}
	return (i != 1);
}
