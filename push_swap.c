/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:44:18 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/15 15:01:46 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool chk_input_args(int argc, char **argv)
{
	int i;
	long num;
	bool err_flag;

	i = 1;
	err_flag = false;
	while (i < argc)
	{
		err_flag = chk_alphabet(argv[i]);
		if (err_flag == true)
			return (err_flag);
		err_flag = is_empty(argv[i]);
		if (err_flag == true)
			return (err_flag);
		err_flag = ft_atoi(argv[i], &num);
		if (err_flag == true)
			return (err_flag);
		i++;
	}
	return (err_flag);
}

char *argv_concatenate(int argc, char **argv)
{
	int i;
	int len;
	char *buf;

	i = 1;
	len = count_in_argv(argc, argv);
	buf = malloc(len + 1);
	ft_strlcpy(buf, "\0", 2);
	while (i < argc)
	{
		ft_strlcat(buf, argv[i], len);
		ft_strlcat(buf, " ", len);
		ft_strlcpy(argv[i], "\0", 2);
		i++;
	}
	return (buf);
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
	char *buf;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		if (argc > 2)
		{
			if (chk_input_args(argc, argv) == true)
				show_err_msg();
			buf = argv_concatenate(argc, argv);
			ft_strlcpy(argv[1], buf, ft_strlen(buf) + 1);
			argc = 2;
			free(buf);
		}
		if (ft_strchr(argv[1], '!') != NULL)
			show_err_msg();
		argv = ft_split(argv[1], ' ');
		if (argv[0] == NULL)
		{
			free_double_pointer(argv);
			show_err_msg();
		}
		initial_stack(&stack_a, argv, -1);
		free_double_pointer(argv);
	}
	is_sorted = chk_sorting(&stack_a);
	if (!is_sorted)
		push_swap(&stack_a, &stack_b);
	finalize_check(stack_a, stack_b);
	return (0);
}
