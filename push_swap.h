#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
void free_double_pointer(char **ptr);
void initial_stack(t_list **a, char **argv, int i);

void calc_index_node(t_list **stack);
int calc_min_pushcost(t_list **stack_a, int *min_index);
int find_index_from_val(t_list **stack, int num_to_find);
int find_val_from_index(t_list **stack, int min_index);
int find_minmax_data(t_list **stack, bool min_logic);
int find_index_of_target(t_list **stack_b, int target, int len_stack);
int find_mid_of_stack(int len);
int min_val_confirmation(t_list **stack_a);
void finalize_check(t_list *stack_a, t_list *stack_b);

int closest_bigger(int data, t_list **stack_a, int len_stack_a);
void calc_target_node_b(t_list **stack_a, t_list **stack_b, int len_stack_a);
void calc_pushcost_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b);
void push_decision_to_a(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b);
void swap_stack_a(t_list **stack_a, int index, int len, int above_mid);

int closest_smaller(int data, t_list **stack_b, int len_stack_b);
void calc_target_node_a(t_list **stack_a, t_list **stack_b, int len_stack_b);
void calc_pushcost_to_b(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b);
void push_decision_to_b(t_list **stack_a, t_list **stack_b, int len_stack_a, int len_stack_b);
void swap_stack_b(t_list **stack_b, int index, int len, int above_mid);

bool chk_sorting(t_list **stack);
int calc_operation(int i, int len);
int calc_swap_target_to_top(t_list **stack, int target, int len_stack);
void four_sorting(t_list **stack_a, t_list **stack_b);
int chk_mid(int mid, int index);
void five_sorting(t_list **stack_a, t_list **stack_b);

void error_handler(char *str, long *num);
void ascending_sort(int *num, int len);
bool chk_duplicate(t_list **tmp);

#endif
