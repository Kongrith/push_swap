#include "push_swap.h"

// void bubble_sort(int *num, int *largest_num, int *second_largest_num, int len)
// {
//     int i;
//     int j;
//     int tmp;

//     i = 0;
//     while (i < len - 1)
//     {
//         j = i + 1;
//         while (j < len)
//         {
//             if (num[j] > num[i])
//             {
//                 tmp = num[i];
//                 num[i] = num[j];
//                 num[j] = tmp;
//             }
//             j++;
//         }
//         i++;
//     }
//     *largest_num = num[0];
//     *second_largest_num = num[1];
// }

void linked_list_to_arr(t_list **stack)
{
    t_list *tmp;
    int arr[3];
    int i;

    i = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        arr[i] = tmp->data;
    }
}

bool chk_sorting(t_list **a)
{
    int len;

    len = count_stack(a);
    linked_list_to_arr(a);

    return (false);
}

// cc chk_sorting.c stack_operation1.c stack_operation2.c stack_operation3.c pushswap_utilities.c -L. -lftprintf
int main()
{
    t_list *stack_a;

    stack_a = NULL;
    push(&stack_a, 3);
    push(&stack_a, 2);
    push(&stack_a, 1);
    display(&stack_a);
    freeList(stack_a);
    return (0);
}