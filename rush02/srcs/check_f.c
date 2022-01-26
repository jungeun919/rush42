/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:09:58 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 18:13:00 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	erase_ptr(int *new_line_ptr, int cnt_newline)
{
	int	i;

	i = 0;
	while (i < cnt_newline)
		new_line_ptr[i++] = 0;
	free(new_line_ptr);
	return (0);
}

int	ft_preprocessing(t_data	**arr, char *file_name)
{
	int		cnt_newline;
	int		*new_line_ptr;
	int		dict_cnt;

	if (ft_cnt_newline(&cnt_newline, file_name))
		return (0);
	if (cnt_newline == 0)
		return (ft_error() - 1);
	new_line_ptr = (int *)malloc(sizeof(int) * cnt_newline);
	if (!new_line_ptr)
		return (0);
	if (ft_find_newline(new_line_ptr, 0, 0, file_name))
		return (erase_ptr(new_line_ptr, cnt_newline));
	*arr = (t_data *)malloc(sizeof(t_data) * cnt_newline);
	if (!(*arr))
		return (0);
	dict_cnt = ft_calpars(*arr, new_line_ptr, cnt_newline, file_name);
	erase_ptr(new_line_ptr, cnt_newline);
	if (dict_cnt == 0)
		return (erase_data(arr, dict_cnt));
	if (ft_is_in_key(*arr, dict_cnt))
		return (ft_error() - 1);
	return (dict_cnt);
}

int	ft_arg_check(int argc, char *argv[])
{
	if (argc == 2 || argc == 3)
	{
		if (argv[argc - 1][0] == '\0')
			return (ft_arg_error());
		if (argv[argc - 1][0] == '+')
			argv[argc - 1][0] = '0';
		if (!ft_str_is_numeric(argv[argc - 1]))
			return (ft_arg_error());
		if (ft_strncmp(argv[argc - 1], "4294967295", \
					ft_strlen(argv[argc - 1])) > 0)
			return (ft_arg_error());
		return (0);
	}
	if (argc == 1)
		return (0);
	return (ft_arg_error());
}

int	ft_can_resolve(t_data *arr, int dict_cnt, unsigned int nbr)
{
	if (nbr <= 20)
	{
		if (ft_num_in_key(arr, dict_cnt, nbr) == -1)
			return (1);
		return (0);
	}
	if (ft_get_key(nbr) != 0 && nbr / ft_get_key(nbr) > 0)
	{
		if (ft_get_key(nbr) < 100)
		{
			if (ft_num_in_key(arr, dict_cnt, ft_get_key(nbr)) == -1)
				return (1);
		}
		else
		{
			if (ft_can_resolve(arr, dict_cnt, nbr / ft_get_key(nbr)))
				return (1);
			if (ft_num_in_key(arr, dict_cnt, ft_get_key(nbr)) == -1)
				return (1);
		}
		if (ft_can_resolve(arr, dict_cnt, nbr % ft_get_key(nbr)))
			return (1);
	}
	return (0);
}
