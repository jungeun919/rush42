/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:03 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/19 11:13:10 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_row_left(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max; //블록크기
	int	count; //볼수있는 블록수

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3) //마지막 열(pos=3, 7, 11, 15)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i] > max) //열 이동(왼->오)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i++;
		}
		if (arr[8 + pos / 4] != count) //arr배열값과 같지않으면 틀림
			return (0);
	}
	return (1);
}

int	check_row_right(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max; //블록크기
	int	count; //볼수있는 블록수

	i = 3;
	max = 0;
	count = 0;
	if (pos % 4 == 3) //마지막 열(pos=3, 7, 11, 15)
	{
		while (0 <= i)
		{
			if (tab[pos / 4][i] > max) //열 이동(오->왼)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i--;
		}
		if (arr[12 + pos / 4] != count)
			return (0);
	}
	return (1);
}
