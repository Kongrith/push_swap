/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_util_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:52:17 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:52:20 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_minmax(t_list **stack, int tmp_min, int tmp_max, bool min_logic)
{
	t_list	*tmp_stack;
	int		answer;

	tmp_stack = *stack;
	while (tmp_stack != NULL)
	{
		if (min_logic == 1)
		{
			if (tmp_stack->data < tmp_min)
			{
				answer = tmp_stack -> data;
				tmp_min = answer;
			}
		}
		else
		{
			if (tmp_stack->data > tmp_max)
			{
				answer = tmp_stack -> data;
				tmp_max = answer;
			}
		}
		tmp_stack = tmp_stack -> next;
	}
	return (answer);
}

/*
หาค่าข้อมูลสูงสุดและต่ำสุดใน Stack
*/
int	find_minmax_data(t_list **stack, bool min_logic)
{
	int	answer;
	int	tmp_min;
	int	tmp_max;

	tmp_min = INT_MAX;
	tmp_max = INT_MIN;
	answer = loop_minmax(stack, tmp_min, tmp_max, min_logic);
	return (answer);
}

/*
ดึงข้อมูลจากเลขลำดับของ stack
*/
int	find_val_from_index(t_list **stack, int min_index)
{
	t_list	*tmp;
	int		data;

	tmp = *stack;
	while (min_index >= 0)
	{
		data = tmp -> data;
		tmp = tmp -> next;
		min_index--;
	}
	return (data);
}

/*
ดึงข้อมูลจากเลขลำดับของ stack
*/
int	find_index_from_val(t_list **stack, int num_to_find)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == num_to_find)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
เติม index ใน linked list
*/
void	calc_index_node(t_list **stack)
{
	t_list	*tmp_a;
	int		i;

	i = 0;
	tmp_a = *stack;
	while (tmp_a != NULL)
	{
		tmp_a -> index = i;
		tmp_a = tmp_a -> next;
		i++;
	}
}
