/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:43:29 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:43:34 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_chk_smaller(t_list **stack_b, int *arr, int data)
{
	t_list	*tmp_b;
	int		i;

	tmp_b = *stack_b;
	i = 0;
	while (tmp_b != NULL)
	{
		arr[i] = data - (tmp_b->data);
		tmp_b = tmp_b->next;
		i++;
	}
	return (i);
}

int	closest_smaller(int data, t_list **stack_b, int len_stack_b)
{
	int	min_diff;
	int	min_index;
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * len_stack_b);
	i = loop_chk_smaller(stack_b, arr, data);
	min_diff = INT_MAX;
	while (i - 1 >= 0)
	{
		if ((arr[i - 1] < min_diff) && (arr[i - 1] > 0))
		{
			min_diff = arr[i - 1];
			min_index = i - 1;
		}
		i--;
	}
	free(arr);
	return (find_val_from_index(stack_b, min_index));
}

void	calc_target_node_a(t_list **stack_a, t_list **stack_b, int len_stack_b)
{
	t_list	*tmp_a;
	int		data;
	int		min_stack_b;
	int		max_stack_b;

	tmp_a = *stack_a;
	min_stack_b = find_minmax_data(stack_b, 1);
	max_stack_b = find_minmax_data(stack_b, 0);
	while (tmp_a != NULL)
	{
		data = tmp_a->data;
		if (data < min_stack_b)
			tmp_a->target = max_stack_b;
		else
			tmp_a->target = closest_smaller(data, stack_b, len_stack_b);
		tmp_a = tmp_a->next;
	}
}

void	calc_pushcost_to_b(t_list **stack_a, t_list **stack_b,
						int len_stack_a, int len_stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;

	i = 0;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a != NULL)
	{
		tmp_a -> push_cost = calc_operation(i, len_stack_a) + \
calc_swap_target_to_top(stack_b, tmp_a->target, len_stack_b);
		tmp_a = tmp_a->next;
		i++;
	}
}

void	swap_stack_b(t_list **stack_b, int index, int len, int above_mid)
{
	while (0 < index && index < len)
	{
		if (above_mid == false)
		{
			rb(stack_b);
			index--;
		}
		else
		{
			rrb(stack_b);
			index++;
		}
	}
}
