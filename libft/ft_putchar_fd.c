/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:08:11 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/06 22:35:23 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	ft_putchar_fd
*	write character c on a specified file descriptor
*
*	write(fd, buffer, nbytes)
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	char s[] = "abcd";
	ft_putchar_fd(s[0], 1);
	return(0);
}*/
