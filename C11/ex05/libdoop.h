/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdoop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:16:53 by melperri          #+#    #+#             */
/*   Updated: 2020/08/24 22:03:01 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDOOP_H
# define LIBDOOP_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		checkerror(char **av);
int		ft_calcul(int a, int b, int (*f)(int, int));
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_div(int a, int b);
int		ft_mul(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
int		error(int e);

#endif
