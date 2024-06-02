#include "push_swap.h"

int calc_operation(int i, int len)
{
    int mid;

    if (len % 2 == 0)
        mid = len / 2;
    else
        mid = len / 2 + 1;
    if (len % 2 == 0)
        if (i < mid)
            return (i);
        else
            return (i - (i - mid) * 2);
    else
    {
        if (i < mid)
            return (i);
        else
            return (i - (1 + (i - mid) * 2));
    }
}

int calc_swap_target_to_top(t_list **stack, int target, int len_stack)
{
    t_list *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->data == target)
            return (calc_operation(i, len_stack));
        tmp = tmp->next;
        i++;
    }
    return (calc_operation(i, len_stack));
}
