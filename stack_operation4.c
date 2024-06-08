/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:54:20 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:54:22 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push เท่ากับ insertFront
 */
void	push(t_list **head, int new_data)
{
	t_list	*newnode;
	t_list	*tmp;

	tmp = *head;
	newnode = malloc(sizeof(t_list));
	newnode -> data = new_data;
	if (*head == NULL)
	{
		newnode -> next = NULL;
		newnode -> prev = NULL;
		*head = newnode;
	}
	else
	{
		tmp -> prev = newnode;
		newnode -> next = *head;
		newnode -> prev = NULL;
		*head = newnode;
	}
}

int	pop(t_list **head)
{
	t_list	*tmp;
	int		pop_data;
	int		len;

	if (*head == NULL)
		return (0);
	len = count_stack(head);
	tmp = *head;
	if (len > 1)
	{
		*head = tmp -> next;
		pop_data = tmp->data;
		free (tmp);
		(*head)-> prev = NULL;
	}
	else
	{
		*head = NULL;
		pop_data = tmp -> data;
		free (tmp);
	}
	return (pop_data);
}

/*
++i
i++
*/
void	initial_stack(t_list **a, char **argv, int i)
{
	long	num;
	bool	err_flag;

	err_flag = false;
	num = 0;
	while (argv[++i])
	{
		error_handler(argv[i], &num);
		insert_last(a, num);
	}
	err_flag = chk_duplicate(a);
	if (err_flag == true)
		show_err_msg();
}

void	min_val_confirmation(t_list **stack_a)
{
	int		min_value;
	int		min_index;
	bool	above_mid;
	int		mid;
	int		len_stack_a;

	len_stack_a = count_stack(stack_a);
	min_value = find_minmax_data(stack_a, 1);
	min_index = find_index_from_val(stack_a, min_value);
	if (min_index != 0)
	{
		mid = find_mid_of_stack(len_stack_a);
		if (min_index < mid)
			above_mid = false;
		else
			above_mid = true;
		swap_stack_a(stack_a, min_index, len_stack_a, above_mid);
	}
}

/*
หา index ของ stack ที่มี push cost น้อยที่สุด
*/
int	calc_min_pushcost(t_list **stack, int *min_index)
{
	t_list	*tmp_a;
	int		target;
	int		min_cost;

	tmp_a = *stack;
	*min_index = 0;
	min_cost = INT_MAX;
	while (tmp_a != NULL)
	{
		if (tmp_a -> push_cost == 0)
			return (tmp_a -> target);
		if (tmp_a->push_cost < min_cost)
		{
			min_cost = tmp_a -> push_cost;
			*min_index = tmp_a -> index;
			target = tmp_a -> target;
		}
		tmp_a = tmp_a -> next;
	}
	return (target);
}
