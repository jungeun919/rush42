/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:23 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/19 11:13:08 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdlib.h>

int	ft_solve(int tab[4][4], int arr[16], int pos)
{
	int	count;

	if (pos == 16)
		return (1);
	count = 1;
	while (count <= 4)
	{
		if (check_double(tab, count, pos) == 1) //이전과 겹치지 않음
		{
			tab[pos / 4][pos % 4] = count; //값 넣음
			if (check_case(tab, arr, pos) == 1) //상하좌우 에서 ok
			{
				if (ft_solve(tab, arr, pos + 1) == 1) //다음 블록 탐색
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0; //백트래킹(이전 함수 호출)
		}
		count++;
	}
	return (0);
}

void	ft_show(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	init_tab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	tab[4][4];
	int	*arr;

	init_tab(tab);
	if (ac != 2) //전달받은 정보의 개수(실행경로, 문자열)
	{
		ft_putstr("Error\n");
		return (0);
	}
	arr = ft_av_atoi(av[1]); //atoi 적용
	if (ft_check(arr, av[1])) //예외처리 걸림
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_solve(tab, arr, 0) == 1) //해가 있음
		ft_show(tab);
	else
		ft_putstr("Error\n");
	free(arr); //동적할당 해제
	return (0);
}
