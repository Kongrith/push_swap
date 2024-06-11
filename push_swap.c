/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:44:18 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:44:19 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool chk_input_buffer(char *buffer)
{
	bool err_flag;

	err_flag = false;
	if (buffer[0] == '\0')
		err_flag = true;
	if (ft_strchr(buffer, '!') != NULL)
		err_flag = true;
	if (is_empty(buffer) == true)
		err_flag = true;
	// if (err_flag = true)
	// {
	// 	// free(buffer);
	// 	show_err_msg();
	// }
	return (err_flag);
}

bool manage_cmd_args(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char *buffer;
	bool err_flag;

	err_flag = false;
	// stack_a = NULL;
	// stack_b = NULL;
	buffer = NULL;
	if (argc == 1)
		return (err_flag = true);
	else if (argc == 2)
	{
		// ft_printf("argc:2\n");
		chk_input_arg(argv);
		argv = ft_split(argv[1], ' ');
		initial_stack(stack_a, argv, -1);
		free_double_pointer(argv);
	}
	else
	{
		buffer = input_concatenation(argc, argv);
		// ft_printf("before buffer:%s\n", buffer);
		// chk_input_buffer(buffer);
		argv = ft_split(buffer, ' ');
		free(buffer);
		// ft_printf("argv[0]:%s\n", argv[0]);
		// ft_printf("argv[1]:%s\n", argv[1]);
		// ft_printf("argv[2]:%s\n", argv[2]);
		// ft_printf("argv[3]:%s\n", argv[3]);
		// ft_printf("argv[4]:%s\n", argv[4]);
		// ft_printf("argv[5]:%s\n", argv[5]);
		initial_stack(stack_a, argv, -1);
		free_double_pointer(argv);
	}
	return (err_flag);
}

static void push_swap(t_list **a, t_list **b)
{
	int len;
	bool is_sorted;

	is_sorted = chk_sorting(a);
	len = count_stack(a);
	if (len < 2)
		return;
	else if (len == 2)
	{
		if (!is_sorted)
			sa(a);
	}
	else if (len == 3)
		three_sorting(a);
	else if (len == 4)
		four_sorting(a, b);
	else if (len == 5)
		five_sorting(a, b);
	else
		turk_algorithm(a, b);
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	bool is_sorted;
	bool err_flag;
	char *buffer;

	err_flag = false;
	stack_a = NULL;
	stack_b = NULL;
	buffer = NULL;
	// err_flag = manage_cmd_args(argc, argv, &stack_a, &stack_b);
	// if (err_flag == true)
	// {
	// 	return (0);
	// }

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		chk_input_arg(argv);
		argv = ft_split(argv[1], ' ');
		initial_stack(&stack_a, argv, -1);
		free_double_pointer(argv);
	}
	else
	{
		buffer = input_concatenation(argc, argv);
		argv = ft_split(buffer, ' ');
		free(buffer);
		initial_stack(&stack_a, argv, -1);
		free_double_pointer(argv);
	}

	// display(&stack_a);
	is_sorted = chk_sorting(&stack_a);
	if (!is_sorted)
		push_swap(&stack_a, &stack_b);
	finalize_check(stack_a, stack_b);
	return (0);
}
