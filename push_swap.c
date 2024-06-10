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

bool is_empty(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isspace((unsigned char)str[i]))
			return 0;
		i++;
	}
	return 1;
}

void chk_input_arg(char **argv)
{
	if (argv[1][0] == '\0')
		show_err_msg();
	if (ft_strchr(argv[1], '!') != NULL)
		show_err_msg();
	if (is_empty(argv[1]) == true)
		show_err_msg();
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

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		chk_input_arg(argv);
		// if (argv[1][0] == '\0')
		// if (*ft_split(argv[1], ' ') == '\0')
		// 	show_err_msg();
		// if (argv[1][0] == '\0' || ft_strchr(argv[1], '!') != NULL)
		// 	show_err_msg();
		argv = ft_split(argv[1], ' ');
		// ft_printf("argv: %s\n", argv);
		initial_stack(&stack_a, argv, -1);
		free_double_pointer(argv);
	}
	else
	{
		// for (int i = 1; i < argc; i++)
		// 	ft_printf("[%d] %s\n", i, argv[i]);
		// int i;
		// i = 0;
		// while (argv[i] != NULL)
		// {
		// 	ft_printf("vector[%d] %s\n", i, argv[i]);
		// 	i++;
		// }
		ft_printf("vector[%d] %s\n", 1, argv[1]);
		ft_printf("vector[%d] %s\n", 2, argv[2]);
		initial_stack(&stack_a, argv, 0);
	}
	is_sorted = chk_sorting(&stack_a);
	if (!is_sorted)
		push_swap(&stack_a, &stack_b);
	finalize_check(stack_a, stack_b);
	return (0);
}
