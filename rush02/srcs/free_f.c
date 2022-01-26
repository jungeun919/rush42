/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:09:36 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/26 17:07:55 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_clear_arr(char *str)
{
	int	i;

	i = 0;
	while (i < 1100)
	{
		str[i] = -1;
		i++;
	}
}

int	erase_data(t_data **arr, int dict_cnt)
{
	int	i;

	i = 0;
	while (i < dict_cnt)
	{
		(*arr)[i].key = 0;
		free((*arr)[i].value);
		(*arr)[i].value = 0;
		i++;
	}
	free((*arr));
	return (0);
}
