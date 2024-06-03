#include "push_swap.h"

void push_to_a_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    calc_index_node(stack_a);
    calc_index_node(stack_b);
    calc_target_node_b(stack_a, stack_b, len_stack_a);
    calc_pushcost_to_a(stack_a, stack_b, len_stack_a, len_stack_b);

    // ##DEBUG ONLY##
    // ft_printf("push_to_a_strategy\n");
    // tmp_b = *stack_b;
    // while (tmp_b != NULL)
    // {
    //     ft_printf("index: %d data: %d target: %d, push_cost: %d\n",
    //               tmp_b->index, tmp_b->data, tmp_b->target, tmp_b->push_cost);
    //     tmp_b = tmp_b->next;
    // }
    push_decision_to_a(stack_a, stack_b, len_stack_a, len_stack_b);

    // ## DEBUG ONLY ##
    // tmp_a = *stack_a;
    // tmp_b = *stack_b;
    // ft_printf("\nSTACK A:\n");
    // display(&tmp_a);
    // ft_printf("\nSTACK B:\n");
    // display(&tmp_b);
    // ft_printf("\n");
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

void push_to_b_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    calc_index_node(stack_a);
    calc_index_node(stack_b);
    calc_target_node_a(stack_a, stack_b, len_stack_b);
    calc_pushcost_to_b(stack_a, stack_b, len_stack_a, len_stack_b);

    // แสดงผลสำหรับการ debug เฉยๆ
    // ft_printf("push_to_b_strategy\n");
    // tmp_a = *stack_a;
    // while (tmp_a != NULL)
    // {
    //     ft_printf("index: %d data: %d target: %d, push_cost: %d\n",
    //               tmp_a->index, tmp_a->data, tmp_a->target, tmp_a->push_cost);
    //     tmp_a = tmp_a->next;
    // }

    push_decision_to_b(stack_a, stack_b, len_stack_a, len_stack_b);

    // ## DEBUG ONLY ##
    // tmp_a = *stack_a;
    // tmp_b = *stack_b;
    // ft_printf("\nSTACK A:\n");
    // display(&tmp_a);
    // ft_printf("\nSTACK B:\n");
    // display(&tmp_b);
    // ft_printf("\n");
}

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
    while (len_stack_a > 5)
    {
        push_to_b_strategy(stack_a, stack_b, len_stack_a, len_stack_b);
        len_stack_a = count_stack(stack_a);
        len_stack_b = count_stack(stack_b);
    }
}

void turk_algorithm(t_list **stack_a, t_list **stack_b)
{
    push_to_stackB(stack_a, stack_b);
    // three_sorting(stack_a);
    // four_sorting(stack_a, stack_b);
    five_sorting(stack_a, stack_b);
    push_back_to_stackA(stack_a, stack_b);
}