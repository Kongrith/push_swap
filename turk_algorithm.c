#include "push_swap.h"

void push_back_to_stackA()
{
}

// void push_to_stackB(t_list **stack_a, t_list **stack_b)
// {
//     int len_stack_a;

//     len_stack_a = count_stack(stack_a);
//     while (len_stack_a > 3)
//     {
//         pb(stack_a, stack_b);
//         len_stack_a = count_stack(stack_a);
//     }
//     // ft_printf("comp\n");
// }

void turk_algorithm(t_list **stack_a, t_list **stack_b)
{
    // push until member = 3
    push_to_stackB(stack_a, stack_b);

    // แสดงผลเฉยๆ
    ft_printf("STACK A:\n");
    display(stack_a);
    ft_printf("\nSTACK B:\n");
    display(stack_b);

    //
    three_sorting(stack_a);

    //
    push_back_to_stackA();

    // แสดงผลเฉยๆ
    ft_printf("STACK A:\n");
    display(stack_a);
    ft_printf("\nSTACK B:\n");
    display(stack_b);
}