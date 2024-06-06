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
    t_list *tmp;
    bool err_flag;
    long num; // int *ptr;

    int len;

    tmp = *a;
    err_flag = false;
    num = 0;
    while (argv[++i])
    {
        err_flag = error_handler(argv[i], &num);
        if (err_flag == true)
        {
            if (tmp != NULL)
                freeList(tmp);
            show_err_msg();
        }
        insertLast(a, num);
    }
    err_flag = chk_duplicate(a);
    tmp = *a;
    if (err_flag)
    {
        freeList(tmp);
        show_err_msg();
    }
    // ptr = malloc(sizeof(int) * i);
    // linked_list_to_arr(a, ptr);
    // len = count_stack(&tmp);
    // ascending_sort(ptr, len);
    // ft_printf("%d\n", ptr[0]);
    // ft_printf("%d\n", ptr[1]);
    // ft_printf("%d\n", ptr[2]);
    // free(ptr);
    // free(tmp);
}