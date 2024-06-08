/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:54:34 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:54:36 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *num, int *largest_num, int *second_largest_num, \
int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[j] > num[i])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
			j++;
		}
		i++;
	}
	*largest_num = num[0];
	*second_largest_num = num[1];
}

void	find_logic_cases(t_list **stack, int *logic_case, \
int *logic_sub_case, int len)
{
	int		i;
	int		*ptr_arr;
	int		largest_num;
	int		second_largest_num;
	t_list	*tmp_stack;

	tmp_stack = *stack;
	ptr_arr = malloc(len * sizeof(int));
	i = 0;
	while (tmp_stack != NULL)
	{
		ptr_arr[i] = tmp_stack->data;
		tmp_stack = tmp_stack->next;
		i++;
	}
	bubble_sort(ptr_arr, &largest_num, &second_largest_num, len);
	tmp_stack = *stack;
	*logic_case = find_index_from_val(&tmp_stack, largest_num);
	*logic_sub_case = find_index_from_val(&tmp_stack, second_largest_num);
	free(ptr_arr);
}

void	case_two(t_list **stack, int logic_case, int logic_sub_case)
{
	if (logic_case == 2)
		if (logic_sub_case == 0)
			sa(stack);
}

void	three_sorting(t_list **stack)
{
	int	logic_case;
	int	logic_sub_case;

	find_logic_cases(stack, &logic_case, &logic_sub_case, 3);
	if (logic_case == 0)
	{
		if (logic_sub_case == 1)
		{
			ra(stack);
			sa(stack);
		}
		else
			ra(stack);
	}
	else if (logic_case == 1)
	{
		if (logic_sub_case == 0)
			rra(stack);
		else
		{
			sa(stack);
			ra(stack);
		}
	}
	case_two(stack, logic_case, logic_sub_case);
}
