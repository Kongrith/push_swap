#include "push_swap.h"

void bubble_sort(int *num, int *largest_num, int *second_largest_num, int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (num[j] > num[i])
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
            j++;
        }
        i++;
    }
    *largest_num = num[0];
    *second_largest_num = num[1];
}

// int find_order_of_num_in_stack(t_list **stack, int num_to_find)
// {
//     int i;
//     t_list *tmp;

//     i = 0;
//     tmp = *stack;
//     while (tmp != NULL)
//     {
//         if (tmp->data == num_to_find)
//             return (i);
//         tmp = tmp->next;
//         i++;
//     }
// }

void find_logic_cases(t_list **stack, int *logic_case, int *logic_sub_case, int len)
{
    int i;
    int *ptr_arr;
    int largest_num;
    int second_largest_num;
    t_list *tmp_stack;

    tmp_stack = *stack;
    ptr_arr = malloc(len * sizeof(int));
    // ptr_arr[0] = tmp_stack->data;
    // ptr_arr[1] = tmp_stack->next->data;
    // ptr_arr[2] = tmp_stack->next->next->data;

    i = 0;
    while (tmp_stack != NULL)
    {
        ptr_arr[i] = tmp_stack->data;
        tmp_stack = tmp_stack->next;
        i++;
    }

    bubble_sort(ptr_arr, &largest_num, &second_largest_num, len);
    tmp_stack = *stack;
    *logic_case = find_index_from_val(&tmp_stack, largest_num);
    *logic_sub_case = find_index_from_val(&tmp_stack, second_largest_num);
    // ft_printf("largest num: %d, second largest: %d\n", largest_num, second_largest_num);
    free(ptr_arr);
}

void three_sorting(t_list **stack)
{
    int logic_case;
    int logic_sub_case;

    find_logic_cases(stack, &logic_case, &logic_sub_case, 3);
    if (logic_case == 0)
    {
        if (logic_sub_case == 1)
        {
            ra(stack);
            sa(stack);
        }
        else
            ra(stack);
    }
    else if (logic_case == 1)
    {
        if (logic_sub_case == 0)
            rra(stack);
        else
        {
            sa(stack);
            ra(stack);
        }
    }
    else
    {
        if (logic_sub_case == 0)
            sa(stack);
    }
}

// cc three_sorting.c stack_operation1.c stack_operation2.c stack_operation3.c
// pushswap_utilities.c -L. -lftprintf
// int main(int argc, char **argv)
// {
//     t_list *stack_a;
//     stack_a = NULL;
//     initial_stack(&stack_a, argv, 0);
//     three_sorting(&stack_a);
//     display(&stack_a);
//     freeList(stack_a);
//     return (0);
// }