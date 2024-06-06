/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:19:30 by kkomasat          #+#    #+#             */
/*   Updated: 2023/11/04 12:53:34 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strchr
 *  locate first "ch" character in the pointer string.
 *
 */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *ptr;

    c = c % 256;
    ptr = (char *)s;
    while (*ptr != '\0')
    {
        if (*ptr == c)
            return (ptr);
        ++ptr;
    }
    if (c == '\0')
        return (ptr);
    return (NULL);
}
/*
int main () {
    const char	str1[] = "This is just a String";
    const char  str2[] = "This is just a String";
    int	ch = 't' + 256;

    printf("original      : %s\n", str1);
    printf("char :%c int:%d\n", ch, ch);
    printf("strchr    (%c) : %s\n", ch, strchr(str1, ch));
    printf("ft_strchr (%c) : %s\n", ch, ft_strchr(str2, ch));
    return 0;
}*/