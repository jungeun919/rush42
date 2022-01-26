/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:10:10 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 14:10:12 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_error(void)
{
	write(1, "Dict Error\n", 11);
	return (1);
}

int	ft_arg_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
