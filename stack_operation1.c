#include "push_swap.h"

void push(t_list **head, int new_data)
{
    t_list *newNode;
    t_list *tmp;

    tmp = *head;
    newNode = malloc(sizeof(t_list));
    newNode->data = new_data;
    if (*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        tmp->prev = newNode;
        newNode->next = *head;
        newNode->prev = NULL;
        *head = newNode;
    }
}
int pop(t_list **head)
{
    t_list *tmp;
    int pop_data;
    int len;

    if (*head == NULL)
        return 0;
    len = count_stack(head);
    tmp = *head;
    if (len > 1)
    {
        *head = tmp->next;
        pop_data = tmp->data;
        free(tmp);
        (*head)->prev = NULL;
    }
    else
    {
        *head = NULL;
        pop_data = tmp->data;
        free(tmp);
    }
    return (pop_data);
}

void pa(t_list **a, t_list **b)
{
    int num1;
    int len;

    len = count_stack(b);
    if (len > 0)
    {
        num1 = pop(b);
        push(a, num1);
    }
    ft_printf("pa\n");
}
void pb(t_list **a, t_list **b)
{
    int num1;
    int len;

    len = count_stack(a);
    if (len > 0)
    {
        num1 = pop(a);
        push(b, num1);
    }
    ft_printf("pb\n");
}

void ra(t_list **a)
{
    int num;
    int len;

    len = count_stack(a);
    if (len > 0)
    {
        num = pop(a);
        insertLast(a, num);
    }
    ft_printf("ra\n");
}
void rb(t_list **b)
{
    int num;
    int len;

    len = count_stack(b);
    if (len > 0)
    {
        num = pop(b);
        insertLast(b, num);
    }
    ft_printf("rb\n");
}
void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}