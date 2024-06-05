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

int chk_num_duplicate()
{
    int count;
    int array[5];
    count = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (array[i] == array[j])
                show_err_msg();
        }
    }
}

/*
++i
i++
*/
void initial_stack(t_list **a, char **argv, int i)
{
    while (argv[++i])
    {
        ft_printf(">%s\n", argv[i]);
        insertLast(a, ft_atoi(argv[i]));
    }
}