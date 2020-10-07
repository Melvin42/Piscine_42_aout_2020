/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:49:08 by melperri          #+#    #+#             */
/*   Updated: 2020/08/19 10:30:40 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		checkbase(char *base);
int		findchar(char c, char *base);
int		stopatoi(char c, char *base);

long	ft_atoi_base(char *nbr, char *base)
{
	long i;
	long res;
	long sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		sign = (nbr[i] == '-') ? -sign : sign;
		i++;
	}
	while (nbr[i] && (stopatoi(nbr[i], base)))
	{
		res = res * ft_strlen(base) + findchar(nbr[i], base);
		i++;
	}
	return (res * sign);
}

long	itoalen(long nb, char *base)
{
	long len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / ft_strlen(base);
		len++;
	}
	return (len);
}

char	*filltab(char *dest, long len, long nb, char *base)
{
	dest[len] = '\0';
	if (nb < 0)
		dest[0] = '-';
	if (nb < 0)
	{
		nb = nb * -1;
		while (--len > 0)
		{
			dest[len] = base[nb % ft_strlen(base)];
			nb = nb / ft_strlen(base);
		}
	}
	else
	{
		while (--len >= 0)
		{
			dest[len] = base[nb % ft_strlen(base)];
			nb = nb / ft_strlen(base);
		}
	}
	return (dest);
}

char	*ft_itoa_base(long nb, char *base)
{
	int		sign;
	long	nb2;
	long	len;
	char	*dest;

	sign = -1;
	nb2 = nb;
	sign = nb < 0 ? -sign : sign;
	if (nb < 0)
		nb2 = nb2 * -1;
	len = itoalen(nb2, base);
	if (nb <= 0)
		len = len + 1;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	dest = filltab(dest, len, nb, base);
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	char	*dest;

	if (!((checkbase(base_from) && checkbase(base_to))))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	dest = ft_itoa_base(nb, base_to);
	return (dest);
}
