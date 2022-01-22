/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:14:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/08 18:45:22 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_square(int y, int x, int r, int c)
{
	if ((r == 1 || r == y) && (c == 1 || c == x))
	{
		ft_putchar('o');
	}
	else if (r == 1 || r == y)
	{
		ft_putchar('-');
	}
	else if (c == 1 || c == x)
	{
		ft_putchar('|');
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
