/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:57:00 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/08 18:45:57 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_square(int y, int x, int r, int c)
{
	if (r == 1 && (c == 1 || c == x))
	{
		ft_putchar ('A');
	}
	else if (r == y && (c == 1 || c == x))
	{
		ft_putchar ('C');
	}
	else if ((c > 1 && c < x) && (r > 1 && r < y))
	{
		ft_putchar (' ');
	}
	else
	{
		ft_putchar ('B');
	}
}

void	rush(int x, int y)
{
	int	r;
	int	c;

	r = 1;
	c = 1;
	if (x > 0 && y > 0)
	{
		while (r <= y)
		{
			while (c <= x)
			{
				ft_square(y, x, r, c);
				c++;
			}
			ft_putchar('\n');
			r++;
			c = 1;
		}
	}
}
