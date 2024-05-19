#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define bool int
#define false 0
#define true 1

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int data;
    struct s_list *prev;
    struct s_list *next;
} t_list;

// Basic Stack Operation

// Mandatory Functions
void turk_algorithm(t_list **a, t_list **b);
void three_sorting(t_list **a, t_list **b);

// Utility Functions
void display(t_list **head);
int count_stack(t_list **head);
void show_err_msg(void);
bool chk_stack_order(t_list **a, t_list **b);
void freeList(t_list *head);

#endif
