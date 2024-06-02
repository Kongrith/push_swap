#include "push_swap.h"

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
            return (min_index);
        if (tmp_a->push_cost < min_cost)
        {
            min_cost = tmp_a->push_cost;
            min_index = tmp_a->index;
        }
        tmp_a = tmp_a->next;
    }
    return (min_index);
}
void push_decision_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a)
{
    int index;
    bool above_mid;
    int mid;

    if (len_stack_a % 2 == 0)
        mid = len_stack_a / 2;
    else
        mid = len_stack_a / 2 + 1;
    index = calc_min_pushcost(stack_b);
    if (index < mid)
        above_mid = true;
    else
        above_mid = false;
    // ft_printf("index: %d\n", index);
    while (0 < index && index < len_stack_a)
    {
        // ft_printf("index: %d\n", index);
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
    pa(stack_a, stack_b);
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
        ft_printf(" %d - %d  (%d)", data, tmp_a->data, (tmp_a->data) - data);
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

void swap_reciever_stack()
{
}

void swap_sender_stack(t_list **stack_a, t_list **stack_b, int index, int len, int above_mid)
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
    pb(stack_a, stack_b);
}

void push_decision_to_b(t_list **stack_a, t_list **stack_b, int len_stack_b)
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
    swap_reciever_stack();
    swap_sender_stack(stack_a, stack_b, index, len_stack_b, above_mid);
    // while (0 < index && index < len_stack_b)
    // {
    //     if (above_mid == true)
    //     {
    //         rb(stack_b);
    //         index--;
    //     }
    //     else
    //     {
    //         rrb(stack_b);
    //         index++;
    //     }
    // }
    // pb(stack_a, stack_b);
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
void push_to_a_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    calc_index_node(stack_a);
    calc_index_node(stack_b);
    calc_target_node_b(stack_a, stack_b, len_stack_a);
    calc_pushcost_to_a(stack_a, stack_b, len_stack_a, len_stack_b);

    // ##DEBUG ONLY##
    ft_printf("push_to_a_strategy\n");
    tmp_b = *stack_b;
    while (tmp_b != NULL)
    {
        ft_printf("index: %d data: %d target: %d, push_cost: %d\n",
                  tmp_b->index, tmp_b->data, tmp_b->target, tmp_b->push_cost);
        tmp_b = tmp_b->next;
    }

    push_decision_to_a(stack_a, stack_b, len_stack_a);
    // decision_to_push(stack_a, stack_b, len_stack_b);

    // pa(stack_a, stack_b);

    // ## DEBUG ONLY ##
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    ft_printf("\nSTACK A:\n");
    display(&tmp_a);
    ft_printf("\nSTACK B:\n");
    display(&tmp_b);
    ft_printf("\n");
}

void push_back_to_stackA(t_list **stack_a, t_list **stack_b)
{
    int len_stack_a;
    int len_stack_b;

    len_stack_a = count_stack(stack_a);
    len_stack_b = count_stack(stack_b);
    if (len_stack_b == 0)
        return;
    while (len_stack_b > 0)
    {
        push_to_a_strategy(stack_a, stack_b, len_stack_a, len_stack_b);
        len_stack_a = count_stack(stack_a);
        len_stack_b = count_stack(stack_b);
    }
}

///
///
///

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

void adjust_stack_b()
{
}

void push_to_b_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    calc_index_node(stack_a);
    calc_index_node(stack_b);
    calc_target_node_a(stack_a, stack_b, len_stack_b);
    calc_pushcost_to_b(stack_a, stack_b, len_stack_a, len_stack_b);
    // แสดงผลสำหรับการ debug เฉยๆ
    ft_printf("push_to_b_strategy\n");
    tmp_a = *stack_a;
    while (tmp_a != NULL)
    {
        ft_printf("index: %d data: %d target: %d, push_cost: %d\n",
                  tmp_a->index, tmp_a->data, tmp_a->target, tmp_a->push_cost);
        tmp_a = tmp_a->next;
    }

    adjust_stack_b();
    push_decision_to_b(stack_a, stack_b, len_stack_b);

    // ## DEBUG ONLY ##
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    ft_printf("\nSTACK A:\n");
    display(&tmp_a);
    ft_printf("\nSTACK B:\n");
    display(&tmp_b);
    ft_printf("\n");
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
    }
}

void turk_algorithm(t_list **stack_a, t_list **stack_b)
{
    push_to_stackB(stack_a, stack_b);
    three_sorting(stack_a);
    ft_printf("\n ### push_back_to_stackA ##\n");
    push_back_to_stackA(stack_a, stack_b);
}