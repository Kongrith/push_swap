/*
why can not use memcmp for array comparison:
https://stackoverflow.com/questions/9120065/best-way-to-compare-two-int-arrays-of-the-same-length

recommended array comparison:
https://stackoverflow.com/questions/24153883/comparing-two-arrays-in-c-element-by-element/36130812#36130812

copy int arr to another
https://stackoverflow.com/questions/8287109/how-to-copy-one-integer-array-to-another
*/

/*
0: not equal => dont sort
1: equal     =>      sorted
*/

#include "push_swap.h"

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

void ascending_sort(int *num, int len)
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
    ft_memmove(sorted_ptr, original_ptr, len * sizeof(int));
    ascending_sort(sorted_ptr, len);
    is_sorted = array_comparison(original_ptr, sorted_ptr, len);
    free(original_ptr);
    free(sorted_ptr);
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
