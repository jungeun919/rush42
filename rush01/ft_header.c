/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:03:02 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/16 19:55:04 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		i;
	int		j;
	char	arr[10];

	i = 0;
	j = 9;
	while (arr[i] < 10)
	{
		arr[i] = '\0';
		i++;
	}
	while (nb > 0)
	{
		arr[j] = (nb % 10 + '0');
		nb /= 10;
		j--;
	}
	while (j < 10)
	{
		if (arr[j] != '\0')
			ft_putchar(arr[j]);
		j++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
