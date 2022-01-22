/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:59:48 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/16 21:51:10 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_col_up(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max; //블록크기
	int	count; //볼수있는 블록수

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3) //마지막 행(pos=12, 13, 14, 15)
	{
		while (i < 4)
		{
			if (tab[i][pos % 4] > max) //행 이동(위->아래)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i++;
		}
		if (arr[pos % 4] != count) //input값과 불일치
			return (0);
	}
	return (1);
}

int	check_col_down(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max; //블록크기
	int	count; //볼수있는 블록수

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3) //마지막 행(pos=12, 13, 14, 15)
	{
		while (0 <= i) //행 이동(아래->위)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i--;
		}
		if (arr[4 + pos % 4] != count)
			return (0);
	}
	return (1);
}
