/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:09:11 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 20:09:16 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	unsigned int	key;
	char			*value;
}	t_data;

void	ft_putnbr(t_data *arr, unsigned int nbr, int dict_cnt);
int		erase_data(t_data **arr, int dict_cnt);
void	ft_clear_arr(char *str);
int		ft_is_in_key(t_data *arr, int dict_cnt);
int		ft_is_initial(unsigned int n);
int		ft_str_is_numeric(char *str);
int		ft_is_space(char ch);
int		ft_is_number(char ch);
int		ft_is_printable(char ch);
int		ft_arg_check(int argc, char *argv[]);
int		ft_can_resolve(t_data *arr, int dict_cnt, unsigned int nbr);
int		ft_preprocessing(t_data	**arr, char *file_name);
void	ft_sort(t_data *tab, int size);
int		ft_calpars(t_data *arr, int *new_line_ptr, \
int cnt_newline, char *file_name);
int		ft_parsing(t_data *arr, int *new_line_ptr, int cnt_newline, int fd);
int		ft_arg_error(void);
int		ft_error(void);
int		ft_check_dict(char *str, int cnt);
char	*ft_find_value(char *str, int len);
int		ft_find_newline(int	*new_line_ptr, int j, int cnt, char *file_name);
int		ft_cnt_newline(int *cnt_newline, char *file_name);
void	ft_putsmall(t_data *arr, unsigned int nbr, int dict_cnt);
void	ft_putstr(char *str);
int		ft_int_len(int nbr);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int len);
int		ft_num_in_key(t_data *arr, int dict_cnt, unsigned int num);
int		ft_get_key(unsigned int n);
int		ft_atoi(char *str);
int		ft_find_key(char *str, int len);

#endif
