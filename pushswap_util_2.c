#include "push_swap.h"

/*
หาค่าข้อมูลสูงสุดและต่ำสุดใน Stack
*/
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

/*
ดึงข้อมูลจากเลขลำดับของ stack
*/
int find_val_from_index(t_list **stack, int min_index)
{
    t_list *tmp;
    int data;

    // data = 0;
    // tmp = *stack;
    // if (tmp == NULL)
    //     return (0);
    while (min_index >= 0)
    {
        data = tmp->data;
        tmp = tmp->next;
        min_index--;
    }
    return (data);
}

/*
ดึงข้อมูลจากเลขลำดับของ stack
*/
int find_index_from_val(t_list **stack, int num_to_find)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->data == num_to_find)
            return (i);
        tmp = tmp->next;
        i++;
    }
}

/*
หา index ของ stack ที่มี push cost น้อยที่สุด
*/
int calc_min_pushcost(t_list **stack, int *min_index)
{
    t_list *tmp_a;
    int target;
    int min_cost;

    tmp_a = *stack;
    *min_index = 0;
    min_cost = INT_MAX;
    while (tmp_a != NULL)
    {
        if (tmp_a->push_cost == 0)
            return (tmp_a->target);
        if (tmp_a->push_cost < min_cost)
        {
            min_cost = tmp_a->push_cost;
            *min_index = tmp_a->index;
            target = tmp_a->target;
        }
        tmp_a = tmp_a->next;
    }
    return (target);
}

/*
เติม index ใน linked list
*/
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