/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:14:00 by kkomasat          #+#    #+#             */
/*   Updated: 2023/11/02 05:13:11 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int ch)
{
	if ((9 <= ch && ch <= 13) || ch == 32)
	{
		return (1);
	}
	else
		return (0);
}

static	int	manage_character(char *str, int *ptr)
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

int	ft_atoi(const char *str)
{
	int	input_number;
	int	sign;
	int	index;

	sign = manage_character((char *) str, &index);
	if (sign == 0)
		return (0);
	input_number = 0;
	while ((str[index] != '\0') && ('0' <= str[index] && str[index] <= '9'))
	{
		input_number = 10 * input_number + (str[index] - '0');
		++index;
	}
	return (input_number * sign);
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
