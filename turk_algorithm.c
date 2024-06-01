#include "push_swap.h"

static void push_back_to_stackA()
{
}

int find_val_from_index(t_list **stack_b, int min_index)
{
    t_list *tmp_b;
    int data;

    tmp_b = *stack_b;
    while (min_index >= 0)
    {
        data = tmp_b->data;
        tmp_b = tmp_b->next;
        min_index--;
    }
    return (data);
}
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
int calc_min_pushcost(t_list **stack_a)
{
    t_list *tmp_a;
    int min_cost;
    int min_index;

    tmp_a = *stack_a;
    min_index = 0;
    min_cost = INT_MAX;
    while (tmp_a != NULL)
    {
        if (tmp_a->push_cost == 0)
            return (tmp_a->index);
        if (tmp_a->push_cost < min_cost)
        {
            min_cost = tmp_a->push_cost;
            min_index = tmp_a->index;
        }
        tmp_a = tmp_a->next;
    }
    return (min_index);
}
int find_minmax_data(t_list **stack, bool min_logic)
{
    t_list *tmp_stack;
    int answer;
    int tmp_min;
    int tmp_max;

    tmp_min = INT_MAX;
    tmp_max = INT_MIN;
    tmp_stack = *stack;
    while (tmp_stack != NULL)
    {
        if (min_logic == 1)
        {
            if (tmp_stack->data < tmp_min)
            {
                answer = tmp_stack->data;
                tmp_min = answer;
            }
        }
        else
        {
            if (tmp_stack->data > tmp_max)
            {
                answer = tmp_stack->data;
                tmp_max = answer;
            }
        }
        tmp_stack = tmp_stack->next;
    }
    return (answer);
}
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
int calc_swap_target_to_top(t_list **stack, int target, int len_stack_b)
{
    t_list *tmp;
    int i;

    i = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->data == target)
            return (calc_operation(i, len_stack_b));
        tmp = tmp->next;
        i++;
    }
    return (calc_operation(i, len_stack_b));
}

void calc_index_node(t_list **stack)
{
    t_list *tmp_a;
    int i;

    i = 0;
    tmp_a = *stack;
    while (tmp_a != NULL)
    {
        tmp_a->index = i;
        tmp_a = tmp_a->next;
        i++;
    }
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
void decision_to_push(t_list **stack_a, t_list **stack_b, int len_stack_b)
{
    int index;
    bool above_mid;
    int mid;

    if (len_stack_b % 2 == 0)
        mid = len_stack_b / 2;
    else
        mid = len_stack_b / 2 + 1;
    index = calc_min_pushcost(stack_a);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;

    while (index > 0)
    {
        if (above_mid == true)
            rb(stack_b);
        else
            rrb(stack_b);
        index--;
    }
    pb(stack_a, stack_b);
}

void push_to_b_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    t_list *tmp_a;

    calc_index_node(stack_a);
    calc_index_node(stack_b);
    calc_target_node_a(stack_a, stack_b, len_stack_b);
    calc_pushcost_to_b(stack_a, stack_b, len_stack_a, len_stack_b);
    decision_to_push(stack_a, stack_b, len_stack_b);
}

/*
ถ้า stack B ว่าง (เริ่มต้นกระบวนการ) ให้ push ไปได้เลย
*/
void push_to_stackB(t_list **stack_a, t_list **stack_b)
{
    int len_stack_a;
    int len_stack_b;
    int min_stack_b;
    int max_stack_b;
    t_list *tmp_a;
    int i;

    i = 1;
    len_stack_b = count_stack(stack_b);
    if (len_stack_b == 0)
        pb(stack_a, stack_b);
    len_stack_a = count_stack(stack_a);
    len_stack_b = count_stack(stack_b);
    while (len_stack_a > 3)
    {
        push_to_b_strategy(stack_a, stack_b, len_stack_a, len_stack_b);
        len_stack_a = count_stack(stack_a);
        len_stack_b = count_stack(stack_b);
        i++;
    }
}

void turk_algorithm(t_list **stack_a, t_list **stack_b)
{
    push_to_stackB(stack_a, stack_b);
    three_sorting(stack_a);
    push_back_to_stackA();
}