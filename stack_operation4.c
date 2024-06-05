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
0: ไม่เจอตัวอักษร
1: เจอตัวอักษร
*/
bool chk_alphabet(char *str)
{
    int i = 0;
    bool err_flag;

    err_flag = false;
    while (str[i])
    {
        if (ft_isalpha(str[i]) || str[i] == '.')
        {
            err_flag = true;
            return (err_flag);
        }
        i++;
    }
    return (err_flag);
}

/*
++i
i++
*/
void initial_stack(t_list **a, char **argv, int i)
{
    int num;
    // int *ptr;
    bool err_flag;
    t_list *tmp;

    err_flag = false;
    num = 0;
    // ptr = malloc(sizeof(int) * 3);
    // ft_printf("%s\n", argv);
    while (argv[++i])
    {
        // ft_printf("%s\n", argv[i]);
        err_flag = chk_alphabet(argv[i]);
        if (err_flag)
            show_err_msg();
        err_flag = ft_atoi(argv[i], &num);
        if (err_flag)
            show_err_msg();
        // ft_printf("num: %d\n", num);
        // ft_printf("\n");
        insertLast(a, num);
    }
    // ft_printf("?????\n");
    // tmp = *a;
    // linked_list_to_arr(a, ptr);

    // ft_printf("%d\n", ptr[0]);
    // ft_printf("%d\n", ptr[1]);
    // ft_printf("%d\n", ptr[2]);
    // free(ptr);
    // free(tmp);
}