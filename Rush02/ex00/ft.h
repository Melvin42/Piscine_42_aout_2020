/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:24:21 by melperri          #+#    #+#             */
/*   Updated: 2020/08/23 23:40:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 10000

typedef struct	s_def
{
	char	*key;
	char	*word;
}				t_def;

int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strcat(char *buf, char *src);
int				get_dict(char *dict, char **dest_dict);
int				check_num(char *str);
char			*extract_key(char *str);
char			*extract_word(char *str, int pos);
t_def			*create_tab_def(char **str);
void			extract_def(char *str, t_def *tab_def);
int				separator_check(char c, char charset);
char			*ft_dupsplit(char *src, char charset);
int				count_strings(char *str, char charset);
char			**ft_split(char *str);
char			**to_trios(char *num);
int				get_last_trio(char **trios, char *num, int j, int *index_trio);
void			print_trio(char *str, t_def *tab_def, char *buf, int nb_sep);
int				print_all(t_def *final_def, char *num);
void			print_sep(int i, t_def *tab_def, char *buf);
t_def			*make_good_def(int i, int j, char **gd_split, char **ge_split);
t_def			*malloc_final_def(char **str);
int				set_up(int ac, char *dd_dict, char *de_dict, char *num);
int				error(int type);
int				check_num(char *str);
char			*skip_zero(char *num);
void			ft_magic(char *buf);
char			**ft_split_string(char *str, char *charset);
int				ft_count_words(char *str, char *sep);
char			*ft_next_opposite(char *str, char *sep);
int				ft_is_sep(char c, char *str);
int				contains(char *str, char c);
int				contains_only(char *str, char c);
char			*ft_strstr(char *str, char *to_find);
int				check_def(char *str);
int				dic_is_valid(char *str);
int				strcmp_num(char *s1, char *s2);
void			ft_free(char *dd_dict, char *de_dict);

#endif
