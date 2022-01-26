/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:11:41 by taehyeok          #+#    #+#             */
/*   Updated: 2022/01/23 18:34:34 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putnbr(t_data *arr, unsigned int nbr, int dict_cnt)
{
	int	i;

	i = 0;
	if (nbr <= 20)
	{
		ft_putsmall(arr, nbr, dict_cnt);
		return ;
	}
	while (i < dict_cnt)
	{
		if (ft_is_initial(arr[i].key) && \
		arr[i].key != 0 && nbr / arr[i].key > 0)
		{
			if (arr[i].key < 100)
				ft_putstr(arr[i].value);
			else
			{
				ft_putnbr(arr, nbr / arr[i].key, dict_cnt);
				ft_putstr(arr[i].value);
			}
			nbr %= arr[i].key;
		}
		i++;
	}
}

int	ft_user_input(t_data **arr, int dict_cnt, int flag)
{
	char	user_str[100];
	int		idx;

	idx = 0;
	while (idx < 100)
		user_str[idx++] = 0;
	read(0, user_str, 100);
	if (user_str[0] == '\n')
		return (ft_arg_error());
	idx = 0;
	if (user_str[idx] == '+')
	{
		flag = 1;
		idx++;
	}
	while (user_str[idx] != '\n')
		idx++;
	user_str[idx] = '\0';
	if (idx > 10 + flag || !ft_str_is_numeric(&user_str[flag]) || \
	ft_strncmp(&user_str[flag], "4294967295", idx) > 0)
		return (ft_arg_error());
	if (ft_can_resolve(*arr, dict_cnt, ft_atoi(&user_str[flag])))
		return (ft_error());
	ft_putnbr(*arr, ft_atoi(&user_str[flag]), dict_cnt);
	return (0);
}

int	end_of_program(void)
{
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		dict_cnt;
	t_data	*arr;

	if (ft_arg_check(argc, argv))
		return (0);
	if (argc == 1 || argc == 2)
		dict_cnt = ft_preprocessing(&arr, "numbers.dict");
	else
		dict_cnt = ft_preprocessing(&arr, argv[1]);
	if (dict_cnt == 0)
		return (0);
	ft_sort(arr, dict_cnt);
	if (argc == 2 || argc == 3)
	{
		if (ft_can_resolve(arr, dict_cnt, ft_atoi(argv[argc - 1])))
			return (ft_error() - 1);
		ft_putnbr(arr, ft_atoi(argv[argc - 1]), dict_cnt);
	}
	else
	{
		if (ft_user_input(&arr, dict_cnt, 0))
			return (0);
	}
	erase_data(&arr, dict_cnt);
	return (end_of_program());
}
