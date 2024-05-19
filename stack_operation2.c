#include "push_swap.h"

void insertLast(t_list **head, int new_data)
{
	t_list *newNode;
	t_list *tmp;

	newNode = malloc(sizeof(t_list));
	newNode->data = new_data;
	newNode->next = NULL;
	tmp = *head;
	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newNode;
		newNode->prev = tmp;
	}
}

int deleteLast(t_list **head)
{
	t_list *tmp;
	int dequeue_data;
	int len;

	if (*head == NULL)
		return 0;
	len = count_stack(head);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	dequeue_data = tmp->data;
	if (len > 1)
	{
		tmp = tmp->prev;
		free(tmp->next);
		tmp->next = NULL;
	}
	else
	{
		*head = NULL;
		free(tmp);
	}
	return (dequeue_data);
}

void rra(t_list **a)
{
	int num;
	int len;

	len = count_stack(a);
	if (len > 0)
	{
		num = deleteLast(a);
		push(a, num);
	}
}

void rrb(t_list **b)
{
	int num;
	int len;

	len = count_stack(b);
	if (len > 0)
	{
		num = deleteLast(b);
		push(b, num);
	}
}

void rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}