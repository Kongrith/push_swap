#include "push_swap.h"

int closest_smaller(int data, t_list **stack_b, int len_stack_b)
{
    t_list *tmp_b;
    int arr[len_stack_b];
    int i;
    int min_diff;
    int min_index;

    tmp_b = *stack_b;
    i = 0;
    while (tmp_b != NULL)
    {
        // ft_printf(" %d - %d  (%d)", data, tmp_b->data, data - (tmp_b->data));
        arr[i] = data - (tmp_b->data);
        tmp_b = tmp_b->next;
        i++;
    }
    min_diff = INT_MAX;
    while (i - 1 >= 0)
    {
        if ((arr[i - 1] < min_diff) && (arr[i - 1] > 0))
        {
            min_diff = arr[i - 1];
            min_index = i - 1;
        }
        i--;
    }
    return (find_val_from_index(stack_b, min_index));
}

void calc_target_node_a(t_list **stack_a, t_list **stack_b, int len_stack_b)
{
    t_list *tmp_a;
    int data;
    int min_stack_b;
    int max_stack_b;

    tmp_a = *stack_a;
    min_stack_b = find_minmax_data(stack_b, 1);
    max_stack_b = find_minmax_data(stack_b, 0);
    while (tmp_a != NULL)
    {
        data = tmp_a->data;
        if (data < min_stack_b)
            tmp_a->target = max_stack_b;
        else
            tmp_a->target = closest_smaller(data, stack_b, len_stack_b);
        tmp_a = tmp_a->next;
    }
}

void calc_pushcost_to_b(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int i;
    t_list *tmp_a;
    t_list *tmp_b;

    i = 0;
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while (tmp_a != NULL)
    {
        tmp_a->push_cost = calc_operation(i, len_stack_a) +
                           calc_swap_target_to_top(stack_b, tmp_a->target, len_stack_b);
        tmp_a = tmp_a->next;
        i++;
    }
}

void swap_stack_b(t_list **stack_b, int index, int len, int above_mid)
{
    while (0 < index && index < len)
    {
        if (above_mid == true)
        {
            rb(stack_b);
            index--;
        }
        else
        {
            rrb(stack_b);
            index++;
        }
    }
}

void push_decision_to_b(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int index;
    bool above_mid;
    int mid;
    int target;

    mid = find_mid_of_stack(len_stack_a);
    target = calc_min_pushcost(stack_a, &index);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;
    swap_stack_a(stack_a, index, len_stack_a, above_mid);
    index = find_index_of_target(stack_b, target, len_stack_b);
    mid = find_mid_of_stack(len_stack_b);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;
    swap_stack_b(stack_b, index, len_stack_b, above_mid);
    pb(stack_a, stack_b);
}