#include "push_swap.h"

void swap_top(t_list **stack)
{
	int num1;
	int num2;

	num1 = pop(stack);
	num2 = pop(stack);
	push(stack, num1);
	push(stack, num2);
}

void sa(t_list **a)
{
	int len;

	len = count_stack(a);
	if (len > 1)
		swap_top(a);
}

void sb(t_list **b)
{
	int len;

	len = count_stack(b);
	if (len > 1)
		swap_top(b);
}

void ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
