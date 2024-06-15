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
    int space_count;
    bool err_flag;

    i = 0;
    space_count = 0;
    while (str[i] != '\0')
    {
        if (chk_space(str[i]))
            space_count += 1;
        i++;
    }
    if (space_count == ft_strlen(str))
        err_flag = true;
    else
        err_flag = false;
    return (err_flag);
}

// bool is_empty(const char *str)
// {
//     int i;
//     bool err_flag;
//     err_flag = false;
//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (chk_space((unsigned char)str[i]) == true)
//         {
//             err_flag = true;
//             return (err_flag);
//         }
//         i++;
//     }
//     return (err_flag);
// }