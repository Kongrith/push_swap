/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:41:19 by kkomasat          #+#    #+#             */
/*   Updated: 2023/10/28 18:24:00 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	strlcat()
function returns the combined length of both src and dst strings (not counting
terminating null character.

Before :                || After :
dst   | src   | size    || dst      | return
------------------------||--------------------
dst\0 | src\0 | 0       || dst\0    | 3			<--- length of src
dst\0 | src\0 | 1       || dst\0    | 4
dst\0 | src\0 | 2       || dst\0    | 5
dst\0 | src\0 | 3       || dst\0    | 6         <--- length of src + dst
dst\0 | src\0 | 4       || dst\0    | 6
dst\0 | src\0 | 5       || dsts\0   | 6			***
dst\0 | src\0 | 6       || dstsr\0  | 6
dst\0 | src\0 | 7       || dstsrc\0 | 6
dst\0 | src\0 | 8       || dstsrc\0 | 6
*/

#include "libft.h"

size_t ft_strlcat(char *dest0, const char *src0, size_t size)
{
    size_t i;
    size_t j;
    char *dest;
    char *src;

    dest = (char *)dest0;
    src = (char *)src0;
    i = 0;
    j = 0;
    if (dest == NULL)
        i = 0;
    else
        while (dest[i] && (i < size))
            ++i;
    while (src[j] && (i + j + 1 < size))
    {
        dest[i + j] = src[j];
        ++j;
    }
    if (i < size)
        dest[i + j] = '\0';
    return (i + ft_strlen(src));
}

/*
    Before :                  || After :
    dst   | src       | size  || dst         | return
    --------------------------||---------------------
    42\0  | bangkok\0 | 0     || 42\0        | 7         <--- length of src
    42\0  | bangkok\0 | 1     || 42\0        | 8
    42\0  | bangkok\0 | 2     || 42\0        | 9
    42\0  | bangkok\0 | 3     || 42\0        | 9
    42\0  | bangkok\0 | 4     || 42b\0       | 9
    42\0  | bangkok\0 | 5     || 42ba\0      | 9
    42\0  | bangkok\0 | 6     || 42ban\0     | 9
    42\0  | bangkok\0 | 7     || 42bang\0    | 9
    42\0  | bangkok\0 | 8     || 42bangk\0   | 9
    42\0  | bangkok\0 | 9     || 42bangko\0  | 9
    42\0  | bangkok\0 | 10    || 42bangkok\0 | 9
    42\0  | bangkok\0 | 11    || 42bangkok\0 | 9

    char dest[12] = "42";
    char src[] = "bangkok";
    printf("%ld\n", strlcat(dest, src, 11));
    printf("dest: %s", dest);

    return(0);
*/