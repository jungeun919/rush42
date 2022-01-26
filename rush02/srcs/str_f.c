/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:28 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 14:11:09 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s1[i] >= '0' && s1[i++] <= '9')
		cnt++;
	if (cnt > 10)
		return (1);
	if (cnt < 10)
		return (-1);
	i = 0;
	while (i < len && s1[i] != '\0' && s2[i] != '\0'\
	&& s1[i] != ':' && !ft_is_space(s1[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_int_len(int nbr)
{
	int	cnt;

	cnt = 1;
	while (nbr >= 10)
	{
		cnt++;
		nbr /= 10;
	}
	return (cnt);
}

void	ft_putstr(char *str)
{
	static int	cnt = 0;
	int			i;

	i = 0;
	if (cnt != 0)
		write(1, " ", 1);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	cnt++;
}

void	ft_putsmall(t_data *arr, unsigned int nbr, int dict_cnt)
{
	int	i;

	i = 0;
	while (i < dict_cnt)
	{
		if (nbr == arr[i].key)
		{
			ft_putstr(arr[i].value);
			return ;
		}
		i++;
	}
}
