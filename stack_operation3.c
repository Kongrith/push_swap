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
void initial_stack(t_list **a, char **argv, int i)
{
	while (argv[++i])
	{
		insertLast(a, ft_atoi(argv[i]));
	}
}

void sa(t_list **a)
{
	int len;

	len = count_stack(a);
	if (len > 1)
		swap_top(a);
	ft_printf("sa\n");
}

void sb(t_list **b)
{
	int len;

	len = count_stack(b);
	if (len > 1)
		swap_top(b);
	ft_printf("sb\n");
}

void ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
