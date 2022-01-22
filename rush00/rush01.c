/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:48:50 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/12 12:50:39 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_square(int y, int x, int r, int c)
{
	if ((r == 1 && c == 1) || ((r != 1 && c != 1) && (r == y && c == x)))
	{
		ft_putchar ('/');
	}
	else if ((r == y && c == 1) || (c == x && r == 1))
	{
		ft_putchar ('\\');
	}
	else if ((r > 1 && r < y) && (c > 1 && c < x))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('*');
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
