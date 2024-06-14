/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_util_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <khkomasa@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:11:33 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/12 00:11:37 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int chk_space(int ch)
{
    if ((9 <= ch && ch <= 13) || ch == 32)
    {
        return (1);
    }
    else
        return (0);
}

bool is_empty(const char *str)
{
    int i;
    bool err_flag;
    // printf("chk_space\n");
    err_flag = false;
    i = 0;
    while (str[i] != '\0')
    {
        if (chk_space((unsigned char)str[i]) == true)
        {
            // printf("chk_space\n");
            err_flag = true;
            return (err_flag);
        }
        i++;
    }
    return (err_flag);
}