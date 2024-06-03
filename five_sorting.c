#include "push_swap.h"

void five_sorting(t_list **stack_a, t_list **stack_b)
{
    int min_value;
    int max_value;
    int index;
    int above_mid_stack_a;
    int len_stack_a;

    len_stack_a = count_stack(stack_a);
    max_value = find_minmax_data(stack_a, 0);
    index = find_index_from_val(stack_a, max_value);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index);
    swap_stack_a(stack_a, index, len_stack_a, above_mid_stack_a);
    pb(stack_a, stack_b);
    len_stack_a = count_stack(stack_a);
    min_value = find_minmax_data(stack_a, 1);
    index = find_index_from_val(stack_a, min_value);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index);
    swap_stack_a(stack_a, index, len_stack_a, above_mid_stack_a);
    pb(stack_a, stack_b);
    three_sorting(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ra(stack_a);
    // min_val_confirmation(stack_a);

    // ## DEBUG ONLY ##
    // ft_printf("\nDEBUG ONLY\n");
    // ft_printf("STACK A:\n");
    // display(stack_a);
    // ft_printf("\nSTACK B:\n");
    // display(stack_b);
}