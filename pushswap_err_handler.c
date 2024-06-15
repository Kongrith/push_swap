/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_err_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:50:45 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:50:46 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show_err_msg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

bool chk_duplicate(t_list **tmp)
{
	int *ptr;
	int len;
	int i;

	len = count_stack(tmp);
	ptr = malloc(sizeof(int) * len);
	linked_list_to_arr(tmp, ptr);
	ascending_sort(ptr, len);
	i = 0;
	while (i < len - 1)
	{
		if (ptr[i] == ptr[i + 1])
		{
			free(ptr);
			return (true);
		}
		i++;
	}
	free(ptr);
	return (false);
}

/*
0: ไม่เจอตัวอักษร
1: เจอตัวอักษร
*/

bool chk_alphabet(char *str)
{
	int i;
	bool err_flag;

	i = 0;
	err_flag = false;
	while (str[i])
	{
		if (ft_isalpha(str[i]) || str[i] == '.' || str[i] == '!' || str[i] == ',')
		{
			err_flag = true;
			return (err_flag);
		}
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	return (err_flag);
}

bool error_handler(char *str, long *num)
{
	bool err_flag;

	err_flag = false;
	err_flag = chk_alphabet(str);
	if (err_flag == true)
		return (err_flag);
	err_flag = is_empty(str);
	if (err_flag == true)
		return (err_flag);
	err_flag = ft_atoi(str, num);
	return (err_flag);
}
