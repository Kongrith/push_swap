#include "push_swap.h"

/* push เท่ากับ insertFront
 */
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

/*
++i
i++
*/
void initial_stack(t_list **a, char **argv, int i)
{
    long num;
    bool err_flag;

    err_flag = false;
    num = 0;
    while (argv[++i])
    {
        error_handler(argv[i], &num);
        insertLast(a, num);
    }
    err_flag = chk_duplicate(a);
    if (err_flag == true)
        show_err_msg();
}