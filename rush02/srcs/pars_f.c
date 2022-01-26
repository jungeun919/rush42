/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:11:01 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 18:10:14 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_parsing(t_data *arr, int *new_line_ptr, int cnt_newline, int fd)
{
	int		j;
	int		i;
	char	buf[1100];

	j = 0;
	i = 0;
	while (i < cnt_newline)
	{
		read(fd, buf, new_line_ptr[i]);
		if (buf[0] == '\n'\
		|| ft_strncmp(buf, "4294967295", new_line_ptr[i]) > 0)
		{
			i++;
			continue ;
		}
		if (ft_check_dict(buf, 0))
		{
			close(fd);
			return (ft_error() - 1);
		}
		arr[j].key = ft_find_key(buf, new_line_ptr[i]);
		arr[j++].value = ft_find_value(buf, new_line_ptr[i++]);
	}
	return (j);
}

int	ft_calpars(t_data *arr, int *new_line_ptr, int cnt_newline, char *file_name)
{
	int		fd;
	int		cnt;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error() - 1);
	cnt = ft_parsing(arr, new_line_ptr, cnt_newline, fd);
	close(fd);
	return (cnt);
}

void	ft_sort(t_data *tab, int size)
{
	int		i;
	int		j;
	t_data	tmp;

	i = size;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (tab[j].key > tab[j - 1].key)
			{
				tmp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = tmp;
			}
			j++;
		}
		i--;
	}
}
