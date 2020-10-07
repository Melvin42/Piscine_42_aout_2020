/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:03 by melperri          #+#    #+#             */
/*   Updated: 2020/08/27 11:44:52 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#define BUFSIZE 28672

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	putstr_error(char **av, int i, int fd)
{
	ft_putstr(basename(av[0]));
	ft_putstr(": ");
	ft_putstr(av[i]);
	ft_putstr(": No such file or directory\n");
	close(fd);
}

int		open_file(char **av, int fd, int size, int i)
{
	int		ret;
	char	buf[BUFSIZE + 1];

	while (av[++i])
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			while (av[i])
			{
				putstr_error(av, i, fd);
				i++;
			}
			return (1);
		}
		size = 0;
		while ((ret = read(fd, buf, BUFSIZE)))
		{
			size = size + ret;
			buf[size] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
	return (0);
}

int		std_out(int size)
{
	int		ret;
	char	buf[BUFSIZE + 1];

	while ((ret = read(0, buf, BUFSIZE)))
	{
		size = size + ret;
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	fd;
	int	size;
	int	i;

	fd = 0;
	size = 0;
	i = 0;
	if (ac == 1)
	{
		std_out(size);
		return (0);
	}
	else
		open_file(av, fd, size, i);
	return (0);
}
