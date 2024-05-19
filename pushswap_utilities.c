#include "push_swap.h"

void display(t_list **head)
{
    t_list *tmp;

    tmp = *head;
    while (tmp != NULL)
    {
        ft_printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int count_stack(t_list **head)
{
    if (*head == NULL)
        return (0);

    t_list *tmp;
    int len;

    len = 0;
    tmp = *head;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        len++;
    }
    return (len);
}

void show_err_msg(void)
{
    ft_printf("Error\n");
    exit(EXIT_SUCCESS);
}

bool chk_stack_order(t_list **a, t_list **b)
{
    bool is_sorted;
    is_sorted = false;

    return (is_sorted);
}

void freeList(t_list *head)
{
    t_list *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}