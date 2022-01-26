/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:35 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 18:12:20 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_cnt_newline(int *cnt_newline, char *file_name)
{
	int		fd;
	char	buf[1100];
	int		i;

	ft_clear_arr(buf);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	while (read(fd, buf, 1024))
	{
		i = 0;
		while (i < 1024 && buf[i] != -1)
		{
			if (buf[i++] == '\n')
				*cnt_newline += 1;
		}
		ft_clear_arr(buf);
	}
	close(fd);
	return (0);
}

int	ft_find_newline(int	*new_line_ptr, int j, int cnt, char *file_name)
{
	int		fd;
	char	buf[1100];
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	while (read(fd, buf, 1024))
	{
		i = 0;
		while (i < 1024 && buf[i] != -1)
		{
			cnt++;
			if (buf[i++] == '\n')
			{
				new_line_ptr[j++] = cnt;
				cnt = 0;
			}
		}
	}
	close(fd);
	return (0);
}

char	*ft_find_value(char *str, int len)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (i < len && str[i] != ':')
		i++;
	i++;
	while (ft_is_space(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!word)
		return (0);
	while (i < len - 1)
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

int	ft_check_dict(char *str, int cnt)
{
	if (*str == '+')
		str++;
	while (*str != ' ' && *str != ':' && *str != '\n')
	{
		if (!ft_is_number(*str++))
			return (1);
		cnt++;
	}
	if (*str == '\n' || cnt == 0)
		return (1);
	while (*str == ' ' && *str != '\n')
		str++;
	if (*str != ':' || *str == '\n')
		return (1);
	str++;
	while (*str == ' ' && *str != '\n')
		str++;
	if (!ft_is_printable(*str) || *str == '\n')
		return (1);
	while (*str != '\n')
	{
		if (!ft_is_printable(*str++))
			return (1);
	}
	return (0);
}
