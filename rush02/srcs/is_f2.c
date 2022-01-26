/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:09:46 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 14:10:55 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char ch)
{
	if (ch == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	ft_is_printable(char ch)
{
	if (ch >= ' ' && ch <= 126)
		return (1);
	return (0);
}
