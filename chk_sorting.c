/*
why can not use memcmp for array comparison:
https://stackoverflow.com/questions/9120065/best-way-to-compare-two-int-arrays-of-the-same-length

recommended array comparison:
https://stackoverflow.com/questions/24153883/comparing-two-arrays-in-c-element-by-element/36130812#36130812

copy int arr to another
https://stackoverflow.com/questions/8287109/how-to-copy-one-integer-array-to-another
*/

#include "push_swap.h"

/*
0: not equal => dont sort
1: equal     =>      sorted
*/
static int array_comparison(int original[], int sorted[], int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (original[i] != sorted[i])
            return (0);
        i++;
    }
    return (1);
}

// static void descending_sort(int *num, int len)
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
<<<<<<< HEAD
// }

static void ascending_sort(int *num, int len)
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
            if (num[j] < num[i])
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

static void linked_list_to_arr(t_list **stack, int *original_ptr)
{
    t_list *tmp;
    int i;

    tmp = *stack;
    i = 0;
    while (tmp != NULL)
    {
        original_ptr[i++] = tmp->data;
        tmp = tmp->next;
    }
}

bool chk_sorting(t_list **stack)
{
    t_list *tmp;
    bool is_sorted;
    int len;
    int *sorted_ptr;
    int *original_ptr;

    tmp = *stack;
    len = count_stack(&tmp);
    original_ptr = malloc(sizeof(int) * len);
    sorted_ptr = malloc(sizeof(int) * len);
    if (original_ptr == NULL || sorted_ptr == NULL)
        return (-1);
    linked_list_to_arr(&tmp, original_ptr);
    // if (original_ptr == NULL || sorted_ptr == NULL)
    //     return (-1);
    // i = 0;
    // while (tmp != NULL)
    // {
    //     original_ptr[i++] = tmp->data;
    //     tmp = tmp->next;
    // }

    ft_memmove(sorted_ptr, original_ptr, len * sizeof(int));
    ascending_sort(sorted_ptr, len);
    is_sorted = array_comparison(original_ptr, sorted_ptr, len);
    // ft_printf(is_sorted);
    // for (int i = 0; i < len; i++)
    //     ft_printf("[%d] original_ptr: %d\n", i, original_ptr[i]);
    // for (int i = 0; i < len; i++)
    //     ft_printf("[%d] sorted_ptr: %d\n", i, sorted_ptr[i]);
    return (is_sorted);
}

/*
cc chk_stack_is_sorted.c stack_operation1.c stack_operation2.c stack_operation3.c pushswap_utilities.c -L. -lftprintf
*/
// int main()
// {
//     t_list *stack;
//     bool is_sorted;

//     stack = NULL;
//     push(&stack, 1);
//     push(&stack, 2);
//     push(&stack, 3);

//     is_sorted = chk_sorting(&stack);
//     ft_printf("is_sorted: %d\n", is_sorted);
//     display(&stack);
//     return (0);
// }
=======
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
>>>>>>> 3aa6da4e8437f4c62c0eca966cba674947ae2d54
