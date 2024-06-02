#include "push_swap.h"

int closest_bigger(int data, t_list **stack_a, int len_stack_a)
{
    t_list *tmp_a;
    int arr[len_stack_a];
    int i;
    int min_diff;
    int min_index;

    tmp_a = *stack_a;
    i = 0;
    while (tmp_a != NULL)
    {
        // ft_printf(" %d - %d  (%d)", data, tmp_a->data, (tmp_a->data) - data);
        arr[i] = (tmp_a->data) - data;
        tmp_a = tmp_a->next;
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
    return (find_val_from_index(stack_a, min_index));
}

void calc_target_node_b(t_list **stack_a, t_list **stack_b, int len_stack_a)
{
    t_list *tmp_b;
    int data;
    int min_stack_a;
    int max_stack_a;

    tmp_b = *stack_b;
    min_stack_a = find_minmax_data(stack_a, 1);
    max_stack_a = find_minmax_data(stack_a, 0);
    while (tmp_b != NULL)
    {
        data = tmp_b->data;
        if (data > max_stack_a)
            tmp_b->target = min_stack_a;
        else
            tmp_b->target = closest_bigger(data, stack_a, len_stack_a);
        tmp_b = tmp_b->next;
    }
}

void calc_pushcost_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int i;
    t_list *tmp_a;
    t_list *tmp_b;

    i = 0;
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while (tmp_b != NULL)
    {
        tmp_b->push_cost = calc_operation(i, len_stack_b) +
                           calc_swap_target_to_top(stack_a, tmp_b->target, len_stack_a);
        tmp_b = tmp_b->next;
        i++;
    }
}

void swap_stack_a(t_list **stack_a, int index, int len, int above_mid)
{
    while (0 < index && index < len)
    {
        if (above_mid == true)
        {
            ra(stack_a);
            index--;
        }
        else
        {
            rra(stack_a);
            index++;
        }
    }
}

void push_decision_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int index;
    bool above_mid;
    int mid;
    int target;

    mid = find_mid_of_stack(len_stack_a);
    target = calc_min_pushcost(stack_b, &index);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;
    swap_stack_b(stack_b, index, len_stack_b, above_mid);
    index = find_index_of_target(stack_a, target, len_stack_a);
    mid = find_mid_of_stack(len_stack_a);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;
    swap_stack_a(stack_a, index, len_stack_a, above_mid);
    pa(stack_a, stack_b);
}
