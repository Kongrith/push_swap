#include "push_swap.h"

int find_index_of_target(t_list **stack_b, int target, int len_stack)
{
    t_list *tmp_b;
    int i;

    i = 0;
    tmp_b = *stack_b;
    while (tmp_b != NULL)
    {
        if (tmp_b->data == target)
            return (tmp_b->index);
        tmp_b = tmp_b->next;
        i++;
    }
}

/*
คำนวน Operation ที่ต้องดำเนินการกับ stack อย่างง่าย
โดยใช้ sequence
*/
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

/*
คำนวน Operation ที่ต้องดำเนินการกับ stack อย่างง่าย
*/
int calc_swap_target_to_top(t_list **stack, int target, int len_stack)
{
    // t_list *tmp;
    // int i;

    // i = 0;
    // tmp = *stack;
    // while (tmp != NULL)
    // {
    //     if (tmp->data == target)
    //         return (calc_operation(i, len_stack));
    //     tmp = tmp->next;
    //     i++;
    // }
    // return (calc_operation(i, len_stack));
    int index;

    index = find_index_of_target(stack, target, len_stack);
    return (calc_operation(index, len_stack));
}