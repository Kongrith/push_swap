#include "push_swap.h"

void four_sorting(t_list **stack_a, t_list **stack_b)
{
    int min_value;
    int min_index;
    int above_mid_stack_a;
    int len_stack_a;

    min_value = find_minmax_data(stack_a, 1);
    min_index = find_index_from_val(stack_a, min_value);
    len_stack_a = count_stack(stack_a);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), min_index);
    swap_stack_a(stack_a, min_index, len_stack_a, above_mid_stack_a);
    pb(stack_a, stack_b);
    three_sorting(stack_a);
    pa(stack_a, stack_b);
    // min_val_confirmation(stack_a);

    // ## DEBUG ONLY ##
    // ft_printf("\nDEBUG ONLY\n");
    // ft_printf("STACK A:\n");
    // display(stack_a);
    // ft_printf("\nSTACK B:\n");
    // display(stack_b);
}