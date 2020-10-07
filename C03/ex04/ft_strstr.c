/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:23:24 by melperri          #+#    #+#             */
/*   Updated: 2020/08/10 11:11:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index[3];

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	if (to_find[index[2]] == 0)
		return (str);
	while (str[index[0]])
	{
		index[2] = 0;
		index[1] = index[0];
		if (str[index[1]] == to_find[index[2]])
		{
			while (to_find[index[2]] && (str[index[1]] == to_find[index[2]]))
			{
				index[2]++;
				index[1]++;
			}
			if (to_find[index[2]] == '\0')
				return (&str[index[0]]);
		}
		index[0]++;
		index[1]++;
	}
	return (0);
}
