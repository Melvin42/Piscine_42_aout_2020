/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:41:01 by melperri          #+#    #+#             */
/*   Updated: 2020/08/26 16:14:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_def	*malloc_final_def(char **str)
{
	t_def	*tab_def;
	int		size;

	size = 0;
	while (str[size])
		size++;
	if (!(tab_def = malloc(sizeof(*tab_def) * (size + 1))))
		return (NULL);
	tab_def[size].key = 0;
	return (tab_def);
}

t_def	*make_good_def(int i, int j, char **good_split, char **give_split)
{
	t_def	*good_def;
	t_def	*give_def;
	t_def	*final_def;

	good_def = create_tab_def(good_split);
	give_def = create_tab_def(give_split);
	final_def = malloc_final_def(good_split);
	while (good_def[++i].key)
	{
		j = 0;
		while (give_def[j].key)
		{
			if (ft_strcmp(good_def[i].key, give_def[j].key) != 0)
				j++;
			else
			{
				final_def[i].key = ft_strdup(give_def[j].key);
				final_def[i].word = ft_strdup(give_def[j].word);
				j++;
			}
		}
	}
	final_def[i].key = 0;
	return (final_def);
}

int		set_up(int ac, char *dd_dict, char *de_dict, char *num)
{
	t_def	*final_def;

	final_def = NULL;
	if (ac == 2)
	{
		final_def = create_tab_def(ft_split(dd_dict));
		return (print_all(final_def, (num = skip_zero(num))));
	}
	else if (ac == 3)
	{
		final_def = make_good_def(-1, 0, ft_split(dd_dict), ft_split(de_dict));
		return (print_all(final_def, (num = skip_zero(num))));
	}
	else
		return (0);
}

int		error(int type)
{
	if (type == 1)
		ft_putstr("Dict Error\n");
	else
		ft_putstr("Error\n");
	return (0);
}

int		main(int ac, char **av)
{
	char	*num;
	char	*dgood_dict;
	char	*dictgive;
	char	*dgive_dict;

	dictgive = NULL;
	dgive_dict = NULL;
	if (get_dict("dict.txt", &dgood_dict) == 1)
		return (error(1));
	if (ac == 2 && check_num(av[1]))
		num = av[1];
	else if (ac == 3 && check_num(av[2]))
	{
		dictgive = av[1];
		num = av[2];
		if (get_dict(dictgive, &dgive_dict) == 1)
			return (error(1));
		if (!dic_is_valid(dgive_dict))
			return (error(1));
	}
	else
		return (error(0));
	if (set_up(ac, dgood_dict, dgive_dict, num) == 1)
			return (0);
	ft_free(dgood_dict, dgive_dict);
}
