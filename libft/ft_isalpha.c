/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:25:44 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/06 22:30:45 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
int	main(void)
{
    char a = 'a';
    printf("test %c: %d %d \n", a, isalpha(a), ft_isalpha(a));
    int  b = 5;
    printf("test %d: %d %d \n", b, isalpha(b), ft_isalpha(b));
    char c = '!';
    printf("test %c: %d %d \n", c, isalpha(c), ft_isalpha(c));
    char  d = 'B';
    printf("test %c: %d %d \n", d, isalpha(d), ft_isalpha(d));
}*/
