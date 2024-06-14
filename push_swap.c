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
#include <stdio.h>

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
		// if (argv[1][0] == '\0' || is_empty(argv[1]))
		if (ft_strchr(argv[1], '!') != NULL)
			show_err_msg();
		argv = ft_split(argv[1], ' ');
		if (argv[0] == NULL)
		{
			free_double_pointer(argv);
			show_err_msg();
		}
		// printf("argv[0]: %s\n", argv[0]);
		initial_stack(&stack_a, argv, -1);
		free_double_pointer(argv);
	}
	else
	{
		initial_stack(&stack_a, argv, 0);
	}

	is_sorted = chk_sorting(&stack_a);
	if (!is_sorted)
		push_swap(&stack_a, &stack_b);
	finalize_check(stack_a, stack_b);
	return (0);
}
