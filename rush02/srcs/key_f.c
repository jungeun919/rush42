/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:21 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 16:05:08 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_num_in_key(t_data *arr, int dict_cnt, unsigned int num)
{
	int	i;

	i = 0;
	while (i < dict_cnt)
	{
		if (arr[i].key == num)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_key(unsigned int n)
{
	if (n >= 1000000000)
		return (1000000000);
	if (n >= 1000000)
		return (1000000);
	if (n >= 1000)
		return (1000);
	if (n >= 100)
		return (100);
	if (n >= 20)
		return (n / 10 * 10);
	if (n >= 0)
		return (n);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (ft_is_number(str[i]) && str[i] != '\0')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);
}

int	ft_find_key(char *str, int len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (*str == '+')
		i = 1;
	while (i < len && !ft_is_space(str[i]) && str[i] != ':')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
