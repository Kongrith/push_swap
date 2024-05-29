#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include "libft.h"
#include "ft_printf.h"

#define bool int
#define false 0
#define true 1

typedef struct s_list
{
    int data;
    int index;
    int target;
    int push_cost;
    struct s_list *prev;
    struct s_list *next;
} t_list;

// typedef struct s_list
// {
//     int largest_num;
//     int largest_order;
// } t_list;

// Basic Stack Operation
void push(t_list **head, int new_data);
int pop(t_list **head);
void insertLast(t_list **head, int new_data);
int deleteLast(t_list **head);
void swap_top(t_list **stack);

// Stack Manipulation
void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rr(t_list **a, t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a, t_list **b);

// Mandatory Functions
void turk_algorithm(t_list **a, t_list **b);
void three_sorting(t_list **stack);

// Utility Functions
void display(t_list **head);
int count_stack(t_list **head);
void show_err_msg(void);
void linked_list_to_arr(t_list **stack, int *original_ptr);
void freeList(t_list *head);
void initial_stack(t_list **a, char **argv, int i);

bool chk_sorting(t_list **stack);

#endif
