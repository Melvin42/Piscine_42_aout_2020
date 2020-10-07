/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 10:49:01 by melperri          #+#    #+#             */
/*   Updated: 2020/08/16 23:22:41 by trouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	zero(int i, int tab[][4]);
void	printtab(int tab[][4]);
int		checkarg(char *str);
int		checkarg1(int argc, char *str);
int		checkerror(int argc, char *str);
void	fill_tab(char *str, int ins[][4]);
int		four_one_row(int y, int sol[][4], int ins[][4], int tower);
int		four_one_col(int x, int sol[][4], int ins[][4], int tower);
int		one_four_row(int y, int sol[][4], int ins[][4], int tower);
int		one_four_col(int x, int sol[][4], int ins[][4], int tower);
int		three_two_row(int y, int sol[][4], int ins[][4]);
int		three_two_col(int x, int sol[][4], int ins[][4]);
int		two_three_row(int y, int sol[][4], int ins[][4]);
int		two_three_col(int x, int sol[][4], int ins[][4]);
int		one_two_row(int y, int sol[][4], int ins[][4]);
int		one_two_col(int x, int sol[][4], int ins[][4]);
int		two_one_row(int y, int sol[][4], int ins[][4]);
int		two_one_col(int x, int sol[][4], int ins[][4]);
int		one_three_row(int y, int sol[][4], int ins[][4]);
int		one_three_col(int x, int sol[][4], int ins[][4]);
int		three_one_row(int y, int sol[][4], int ins[][4]);
int		three_one_col(int x, int sol[][4], int ins[][4]);
int		three_three_col(int ins[][4]);
int		one_one_col(int ins[][4]);
int		four_four_col(int ins[][4]);
int		four_three_col(int ins[][4]);
int		three_four_col(int ins[][4]);
int		four_two_col(int ins[][4]);
int		two_four_col(int ins[][4]);
int		three_three_row(int ins[][4]);
int		one_one_row(int ins[][4]);
int		four_four_row(int ins[][4]);
int		four_three_row(int ins[][4]);
int		three_four_row(int ins[][4]);
int		four_two_row(int ins[][4]);
int		two_four_row(int ins[][4]);
int		two_two_col(int sol[][4], int ins[][4]);
int		two_two_row(int sol[][4], int ins[][4]);
int		checkcols(int x, int sol[][4], int ins[][4], int tower);
int		checkrows(int y, int sol[][4], int ins[][4], int tower);
int		ins_col_err(int ins[][4]);
int		ins_row_err(int ins[][4]);
void	backtrack(int x, int y, int sol[][4], int ins[][4], int *fin);

#endif
