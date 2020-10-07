/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:36:19 by htizi             #+#    #+#             */
/*   Updated: 2020/08/23 23:01:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcat(char *buf, char *src)
{
	int	i;
	int j;

	i = 0;
	j = ft_strlen(buf);
	while (src[i])
	{
		buf[j] = src[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

int		print_first_digit(char *str, t_def *tab_def, int i, char *buf)
{
	if (i == 0 && str[i] > '0' && str[i] <= '9')
	{
		ft_strcat(buf, tab_def[str[i] - 48].word);
		ft_strcat(buf, " ");
		ft_strcat(buf, tab_def[28].word);
		ft_strcat(buf, " ");
		i++;
	}
	if (i == 1 && str[i] >= '2' && str[i] <= '9')
	{
		ft_strcat(buf, tab_def[(20 + str[i] - 48 - 2)].word);
		ft_strcat(buf, " ");
		i++;
	}
	return (i);
}

void	print_trio(char *str, t_def *tab_def, char *buf, int nb_sep)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '0')
			i++;
		i = print_first_digit(str, tab_def, i, buf);
		if (i == 1 && str[i] == '1')
		{
			ft_strcat(buf, tab_def[(10 + str[i + 1] - 48)].word);
			if (nb_sep > 0)
				ft_strcat(buf, " ");
			return ;
		}
		if (i == 2 && str[i] > '0' && str[i] <= '9')
		{
			ft_strcat(buf, tab_def[str[i] - 48].word);
			if (nb_sep > 0)
				ft_strcat(buf, " ");
			i++;
		}
	}
}

void	print_sep(int i, t_def *tab_def, char *buf)
{
	if (i > 0)
	{
		ft_strcat(buf, tab_def[i + 28].word);
		ft_strcat(buf, " ");
	}
}

int		print_all(t_def *defs, char *num)
{
	char	buf[2300];
	int		i;
	int		nb_sep;
	char	**trios;

	if (*num == '0' && ft_strlen(num) == 1)
		ft_putstr(defs[0].word);
	trios = to_trios(num);
	i = 0;
	trios[i - 1] = NULL;
	while (trios[i] != NULL)
		i++;
	i--;
	nb_sep = i + 1;
	while (i >= 0)
	{
		print_trio(trios[i], defs, buf, i);
		if (!(trios[i][0] == '0' && trios[i][1] == '0' && trios[i][2] == '0'))
			print_sep(i, defs, buf);
		i--;
	}
	ft_magic(buf);
	write(1, "\n", 1);
	return (1);
}
