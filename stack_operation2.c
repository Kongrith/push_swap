/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:53:53 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:53:55 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_last(t_list **head, int new_data)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = malloc(sizeof(t_list));
	new_node -> data = new_data;
	new_node -> next = NULL;
	tmp = *head;
	if (*head == NULL)
	{
		new_node -> prev = NULL;
		*head = new_node;
	}
	else
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = new_node;
		new_node -> prev = tmp;
	}
}

int	deletelast(t_list **head)
{
	t_list	*tmp;
	int		dequeue_data;
	int		len;

	if (*head == NULL)
		return (0);
	len = count_stack(head);
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp->next;
	dequeue_data = tmp->data;
	if (len > 1)
	{
		tmp = tmp -> prev;
		free(tmp -> next);
		tmp -> next = NULL;
	}
	else
	{
		*head = NULL;
		free(tmp);
	}
	return (dequeue_data);
}

void	rra(t_list **a)
{
	int	num;
	int	len;

	len = count_stack(a);
	if (len > 0)
	{
		num = deletelast(a);
		push(a, num);
	}
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	int	num;
	int	len;

	len = count_stack(b);
	if (len > 0)
	{
		num = deletelast(b);
		push(b, num);
	}
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
