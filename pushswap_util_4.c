/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_util_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:53:14 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:53:16 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_size_buffer(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

void clean_newline(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		ft_printf("ch[%d] %d\n", i, buffer[i]);
		if (buffer[i] == '\n')
			buffer[i] = ' ';
		i++;
	}
}

char *input_concatenation(int argc, char **argv)
{
	int i;
	int j;
	char **ptr_arr;
	char *buffer;
	int len;
	long num;

	len = find_size_buffer(argc, argv);
	buffer = malloc(sizeof(char) * len + 1);
	buffer[0] = '\0';
	i = 1;
	while (i < argc)
	{
		// ft_printf("i:%d\n", i);
		if (chk_input_buffer(argv[i]) || ft_atoi(argv[i], &num) || chk_alphabet(argv[i]))
		{
			free(buffer);
			show_err_msg();
		}
		// j = 0;
		// ptr_arr = ft_split(argv[i], ' ');
		// while (ptr_arr[j] != NULL)
		// {
		// 	ft_strlcat(buffer, ptr_arr[j], 100);

		// 	j++;
		// }
		ft_strlcat(buffer, argv[i], 200);
		ft_strlcat(buffer, " ", 200);
		i++;
	}
	// buffer[i] = '\0';
	// free_double_pointer(ptr_arr);
	// ft_printf("before clean buffer:%s\n", buffer);
	// clean_newline(buffer);
	return (buffer);
}

void chk_input_arg(char **argv)
{
	bool err_flag;

	err_flag = false;
	if (argv[1][0] == '\0')
		err_flag = true;
	if (ft_strchr(argv[1], '!') != NULL)
		err_flag = true;
	if (is_empty(argv[1]) == true)
		err_flag = true;
	if (err_flag == true)
	{
		show_err_msg();
	}
}