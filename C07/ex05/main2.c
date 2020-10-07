/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:07:12 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 11:12:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	**ft_split(char *split, char *charset);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	(void)ac;
	char **split;

	split = ft_split(av[1], av[2]);

	int i;

	i = 0;
	while (split[i])
	{
		ft_putstr(split[i]);
		ft_putstr("\n");
		i++;
	}
	printf("%s\n", split[i]);
	return (0);
}
