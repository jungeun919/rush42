/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:57:47 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/19 11:07:45 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_av_atoi(char *av)
{
	int	*arr;
	int	i;

	i = 0;
	//malloc의 반환형이 void* 이므로 (int *)형태로 형변환
	//arr = (int *)malloc(sizeof(int) * 16);
	while (*av) //NULL이 아닐떄까지
	{
		if (*av != ' ' && *av != '\n') //공백이거나 개행문자가 아니면
		{
			arr[i] = *av - '0'; //문자->숫자로
			i++; //배열인덱스
		}
		av++; //인자인덱스
	}
	return (arr);
}

int	ft_check(int arr[], char str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4' //현재 문자가 1~4
			&& str[i + 1] >= '1' && str[i + 1] <= '4') //다음문자가 1~4
			return (1); //Error
		i++;
	}
	i = 0;
	while (arr[i])
		i++;
	if (i != 16)
		return (1);
	return (0);
}
