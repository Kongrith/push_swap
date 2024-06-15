/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:14:00 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/15 14:29:50 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int ch)
{
	if ((9 <= ch && ch <= 13) || ch == 32)
	{
		return (1);
	}
	else
		return (0);
}

static int	manage_character(char *str, int *ptr)
{
	int	sign;
	int	flag;
	int	index;

	sign = 1;
	flag = 0;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	while (str[index] && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-' && flag == 0)
		{
			sign = -1;
			flag = 1;
		}
		else if (str[index] == '+' && flag == 0)
			flag = 1;
		else
			return (0);
		index++;
	}
	*ptr = index;
	return (sign);
}

bool	chk_overflow(long *num, long input_number, int sign)
{
	bool	err_flag;

	*num = input_number * sign;
	err_flag = false;
	if (*num < INT_MIN || *num > INT_MAX)
		err_flag = true;
	return (err_flag);
}

bool	ft_atoi(const char *str, long *num)
{
	long	input_number;
	int		sign;
	int		index;
	bool	err_flag;

	err_flag = false;
	sign = manage_character((char *)str, &index);
	if (sign == 0 || str[index] == '\0')
	{
		err_flag = true;
		return (err_flag);
	}
	input_number = 0;
	while ((str[index] != '\0') && ('0' <= str[index] && str[index] <= '9'))
	{
		input_number = 10 * input_number + (str[index] - '0');
		++index;
	}
	if (str[index] == '-' || str[index] == '+' || str[index] == '!')
	{
		err_flag = true;
		return (err_flag);
	}
	err_flag = chk_overflow(num, input_number, sign);
	return (err_flag);
}

/*
int	main()
{
	// input: +-54, expected: 0, my result: -54
	printf("expected: 0, ft_atoi:%d\n", ft_atoi("+-54"));

	// input: -+48, expected: 0, my result: -48
	printf("expected: 0, ft_atoi:%d\n", ft_atoi("-+48"));

	// input: --47, expected: 0, my result: -47
	printf("expected: 0, ft_atoi:%d\n", ft_atoi("--47"));

	// input: ++54, expected: 0, my result: -54
	printf("expected: 0, ft_atoi:%d\n", ft_atoi("++54"));
	return (0);
}*/
