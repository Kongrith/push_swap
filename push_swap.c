/*
ref: https://www.youtube.com/watch?v=wRvipSG4Mmk&t=441s

Pseudo Code:
Declare pointers to two data stuctures/linked lists, one for stack 'a' and another for stack 'b'
    Set both pointers to NULL to avoid undefined behaviour and indicate we 're starting with empty stacks
Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
    If errors, return error
Handle both cases of input, whether a variable number of cmd, or as a string
    If the input of numbers is a string, call 'split()' to split the substring
Initialize stack 'a' by appending each input number as a node to stack 'a'
    Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or '+' '-' signs
        If errors found, free stack 'a' and return error
    Check for each input, if it is a long integer
        If the input is a string, convert it to a long integer
    Append the nodes to stack 'a'
Check if stack 'a' is sorted
    If not sorted, implement these algorithms
        Check for 2 numbers
            If so, simply swap the numbers
        Check for 3 numbers
            If so, implement our sinple 'sort three' algorithm
        Check if the stack has more than 3 numbers
            If so, implement 'Turk Algorithm'


ref: https://stackoverflow.com/questions/7631282/pointer-to-pointer-with-argv

argv
+----+          +----+
| .  |   --->   | .  |  ---> "./pointer\0"
+----+          +----+
                | .  |  ---> "one\0"
                +----+
                | .  |  ---> "two\0"

*/

#include "push_swap.h"

/* push เท่ากับ insertFront
 */
// void push(t_list **head, int new_data)
// {
//     t_list *newNode;
//     t_list *tmp;

//     tmp = *head;
//     newNode = malloc(sizeof(t_list));
//     newNode->data = new_data;
//     if (*head == NULL)
//     {
//         newNode->next = NULL;
//         newNode->prev = NULL;
//         *head = newNode;
//     }
//     else
//     {
//         tmp->prev = newNode;
//         newNode->next = *head;
//         newNode->prev = NULL;
//         *head = newNode;
//     }
// }

// void initial_stack(t_list **a, char **argv, int i)
// {
//     while (argv[++i])
//     {
//         insertLast(a, ft_atoi(argv[i]));
//     }
// }

static void push_swap(t_list **a, t_list **b)
{
    int len;
    bool is_sorted;

    is_sorted = chk_sorting(a);
    len = count_stack(a);
    if (len < 2)
    {
        return;
    }
    else if (len == 2)
    {
        if (!is_sorted)
        {
            swap_top(a);
            ft_printf("sa\n");
        }
    }
    else if (len == 3)
        three_sorting(a);
    else
    {
        turk_algorithm(a, b);
    }
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    bool is_sorted;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    else if (argc == 2)
    {
        if (argv[1][0] == '\0')
            show_err_msg();
        argv = ft_split(argv[1], ' ');
        initial_stack(&stack_a, argv, -1);
    }
    else
        initial_stack(&stack_a, argv, 0);
    is_sorted = chk_sorting(&stack_a);
    if (!is_sorted)
    {
        push_swap(&stack_a, &stack_b);
    }

    // ## DEBUG ONLY ##
    ft_printf("\nDEBUG ONLY\n");
    ft_printf("STACK A:\n");
    display(&stack_a);
    ft_printf("\nSTACK B:\n");
    display(&stack_b);

    return (0);
}