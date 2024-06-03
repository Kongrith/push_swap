#include "push_swap.h"

int chk_mid(int mid, int index)
{
    int above_mid;

    if (index < mid)
        above_mid = false;
    else
        above_mid = true;
    return (above_mid);
}

// Joint instructions(ss, rr, rrr);
void joint_instructions_a(t_list **stack_a, t_list **stack_b, int index_stack_a, int index_stack_b,
                          int above_mid_stack_a, int above_mid_stack_b, int len_stack_a, int len_stack_b)
{
    while ((0 < index_stack_a && index_stack_a < len_stack_a) && (0 < index_stack_b && index_stack_b < len_stack_b))
    {
        if (above_mid_stack_a && above_mid_stack_b)
        {
            rrr(stack_a, stack_b);
            index_stack_a++;
            index_stack_b++;
        }
        else
        {
            if (index_stack_a == 1 && index_stack_b == 1)
                ss(stack_a, stack_b);
            else
                rr(stack_a, stack_b);
            index_stack_a--;
            index_stack_b--;
        }
    }
    len_stack_a = count_stack(stack_a);
    len_stack_b = count_stack(stack_b);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
    above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
    swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
    swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
}

// void joint_instructions_b(t_list **stack_a, t_list **stack_b, int index_stack_a, int index_stack_b,
//                           int above_mid_stack_a, int above_mid_stack_b, int len_stack_a, int len_stack_b)
// {
//     while ((2 < index_stack_a && index_stack_a < len_stack_a) || (2 < index_stack_b && index_stack_b < len_stack_b))
//     {
//         if (above_mid_stack_a && above_mid_stack_b)
//         {
//             rrr(stack_a, stack_b);
//             index_stack_a++;
//             index_stack_b++;
//         }
//         else
//         {
//             if (index_stack_a == 1 && index_stack_b == 1)
//                 ss(stack_a, stack_b);
//             else
//                 rr(stack_a, stack_b);
//             index_stack_a--;
//             index_stack_b--;
//         }
//     }
//     swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
//     swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
// }

void push_decision_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int target;
    int index_stack_a;
    int index_stack_b;
    bool above_mid_stack_a;
    bool above_mid_stack_b;

    target = calc_min_pushcost(stack_b, &index_stack_b);
    index_stack_a = find_index_of_target(stack_a, target, len_stack_a);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);

    above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);

    if (above_mid_stack_a && above_mid_stack_b)
    {
        joint_instructions_a(stack_a, stack_b, index_stack_a, index_stack_b,
                             above_mid_stack_a, above_mid_stack_b, len_stack_a, len_stack_b);
    }
    else
    {
        swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
        swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
    }
    pa(stack_a, stack_b);
}

void push_decision_to_b(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b)
{
    int target;
    int index_stack_a;
    int index_stack_b;
    bool above_mid_stack_a;
    bool above_mid_stack_b;

    target = calc_min_pushcost(stack_a, &index_stack_a);
    above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
    index_stack_b = find_index_of_target(stack_b, target, len_stack_b);
    above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
    // swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
    // swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
    // pb(stack_a, stack_b);

    // int target;
    // int index_stack_a;
    // int index_stack_b;
    // bool above_mid_stack_a;
    // bool above_mid_stack_b;

    // target = calc_min_pushcost(stack_a, &index_stack_a);
    // index_stack_b = find_index_of_target(stack_b, target, len_stack_b);
    // above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
    // above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
    // if (above_mid_stack_a && above_mid_stack_b)
    // {
    //     joint_instructions_b(stack_a, stack_b, index_stack_a, index_stack_b,
    //                          above_mid_stack_a, above_mid_stack_b, len_stack_a, len_stack_b);
    // }
    // else
    // {
    //     swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
    //     swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
    // }
    swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
    swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
    pb(stack_a, stack_b);
}