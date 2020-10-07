/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:06:20 by melperri          #+#    #+#             */
/*   Updated: 2020/08/26 21:16:05 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <libgen.h>

# define BUF_SIZE 1

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		checkarg(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		while (av[1][i])
		{
			if (av[1][0] != '-')
				return (0);
			if (av[1][1] != 'c')
				return (0);
			if (i > 1 && (!(av[1][i] >= '0' && av[1][i] <= '9')))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}


int		open_file(char **av)
{
	int		i;
	int		fd;
	int		ret;
	int		size;
	char	buf[BUF_SIZE + 1];

	i = 1;
	size = 0;
	while (av[i])
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			while (av[i])
			{
				ft_putstr(basename(av[0]));
				ft_putstr(": option requires an argument -- c\n")
					close(fd);
				i++;
			}
			return (1);
		}
		while ((ret = read(fd, buf, 1)))
		{
			size = size + ret;
			buf[ret] = '\0';
		}
		close(fd);
		i++;
	}
	printf("%d\n", size);
	return (size);
}

int		print_tail(char *av, int size)
{
	int		i;
	int		fd;
	int		ret;
	int		size;
	char	buf[BUF_SIZE + 1];

	i = 1;
	size = 0;
	while (av[i])
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			return (1);
		}
		while ((ret = read(fd, buf, 1)))
		{
			size = size + ret;
			buf[ret] = '\0';
		}
		close(fd);
		i++;
	}
	return (size);
}

int	main(int ac, char **av)
{
	int	size;
	int	i;

	if (ac < 2)
	{
		ft_putstr(basename(av[0]));
		ft_putstr(": option requires an argument -- c\n")
	}
	if (checkarg(ac, av) == 1)
	{
		i = 1;
		while (av[i])
		{
			if (open_file(av[i]) != 1)
			{
				size = open_file(av);
				print_tail(av, size);
			}
		}
	}
	return (0);
}
