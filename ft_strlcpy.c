/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:36:22 by kkomasat          #+#    #+#             */
/*   Updated: 2023/10/28 18:23:49 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcpy
copy a size-bounded string to destination with specific blocks.

*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	index;

	length = ft_strlen((char *) src);
	index = 0;
	if (size == 0)
		return (length);
	while (index < size - 1 && index < length)
	{
		*(dst + index) = *(src + index);
		++index;
	}
	*(dst + index) = '\0';
	while (src[index] != '\0')
		++index;
	return (index);
}
/*
int	main(void)
{
	char src1[] = "abcde";
	char dest1[] = "";

	printf("%ld \n", ft_strlcpy(dest1, src1, 2));
	printf("%s \n", dest1);
}*/
