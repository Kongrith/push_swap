/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 04:16:43 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/06 22:31:31 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memmove
copy a memory block where source and destination can overlap
issue: https://github.com/alelievr/libft-unit-test/pull/146

a) backward copy
|_;_;_;_;_;_|          (source)
      |_;_;_;_;_;_|    (destination)
            <-<-<-^    start from the end to shift the values to the right

b) forward copy
      |_;_;_;_;_;_|    (source)
|_;_;_;_;_;_|          (destination)
^->->->                start from the beginning to shift the values to the left
*/

#include "libft.h"

static char	*backward_copy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		*(dest + i - 1) = *(src + i - 1);
		--i;
	}
	return (dest);
}

static char	*forward_copy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	return (dest);
}

void	*ft_memmove(void *dest0, const void *src0, size_t len)
{
	char	*dest;
	char	*src;

	dest = (char *)dest0;
	src = (char *)src0;
	if (src == dest)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		dest = backward_copy(dest, src, len);
	else
		dest = forward_copy(dest, src, len);
	return (dest);
}
