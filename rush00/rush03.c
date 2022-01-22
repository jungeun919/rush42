/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:23:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/08 18:46:11 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_square(int y, int x, int r, int c)
{
	if ((r == 1 || r == y) && (c == 1))
	{
		ft_putchar('A');
	}
	else if ((r == 1 || r == y) && (c == x))
	{
		ft_putchar('C');
	}
	else if ((r == 1 || r == y) || (c == 1 || c == x))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
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
