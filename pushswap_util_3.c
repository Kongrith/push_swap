#include "push_swap.h"

int find_mid_of_stack(int len)
{
    int mid;

    if (len % 2 == 0)
        mid = len / 2;
    else
        mid = len / 2 + 1;
    return (mid);
}

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

    mid = find_mid_of_stack(len);
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
    int index;

    index = find_index_of_target(stack, target, len_stack);
    return (calc_operation(index, len_stack));
}

int min_val_confirmation(t_list **stack_a)
{
    int min_value;
    int min_index;
    bool above_mid;
    int mid;
    int len_stack_a;

    len_stack_a = count_stack(stack_a);
    min_value = find_minmax_data(stack_a, 1);
    min_index = find_index_from_val(stack_a, min_value);

    if (min_index != 0)
    {
        mid = find_mid_of_stack(len_stack_a);
        if (min_index < mid)
            above_mid = true;
        else
            above_mid = false;
        swap_stack_a(stack_a, min_index, len_stack_a, above_mid);
    }
}