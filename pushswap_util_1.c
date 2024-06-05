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

void linked_list_to_arr(t_list **stack, int *original_ptr)
{
    t_list *tmp;
    int i;

    tmp = *stack;
    i = 0;
    while (tmp != NULL)
    {
        original_ptr[i++] = tmp->data;
        tmp = tmp->next;
    }
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

void free_double_pointer(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}