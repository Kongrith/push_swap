/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_util_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <khkomasa@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:11:33 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/15 15:16:38 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_space(int ch)
{
	if ((9 <= ch && ch <= 13) || ch == 32)
	{
		return (1);
	}
	else
		return (0);
}

bool	is_empty(const char *str)
{
	int		i;
	int		space_count;
	bool	err_flag;

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

int	count_in_argv(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (len);
}
