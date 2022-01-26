/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:47 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 14:10:49 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_initial(unsigned int n)
{
	if (n >= 0 && n <= 20)
		return (1);
	if (n <= 100 && n % 10 == 0)
		return (1);
	if (n == 1000 || n == 1000000 || n == 1000000000)
		return (1);
	return (0);
}

int	ft_is_in_key(t_data *arr, int dict_cnt)
{
	int	i;
	int	j;

	i = 1;
	while (i < dict_cnt)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i].key == arr[j].key)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
