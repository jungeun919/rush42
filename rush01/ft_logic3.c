/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:12 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/19 11:13:17 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

//이전 블록 (행, 열) 겹치는 값이 있는지 확인
int	check_double(int tab[4][4], int count, int pos)
{
	int	i;

	i = 0;
	while (i < pos / 4) //행
	{
		if (tab[i][pos % 4] == count) //count 블록
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % 4) //열
	{
		if (tab[pos / 4][i] == count)
			return (0);
		i++;
	}
	return (1);
}

int	check_case(int tab[4][4], int arr[16], int pos)
{
	if (check_row_left(tab, arr, pos) == 0) //행 왼쪽에서 봤을때 값이 다르면
		return (0); //Error
	if (check_row_right(tab, arr, pos) == 0)
		return (0);
	if (check_col_down(tab, arr, pos) == 0)
		return (0);
	if (check_col_up(tab, arr, pos) == 0)
		return (0);
	return (1);
}
