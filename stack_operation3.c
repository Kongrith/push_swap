/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:54:08 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:54:09 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list **stack)
{
	int	num1;
	int	num2;

	num1 = pop(stack);
	num2 = pop(stack);
	push(stack, num1);
	push(stack, num2);
}

void	sa(t_list **a)
{
	int	len;

	len = count_stack(a);
	if (len > 1)
		swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	int	len;

	len = count_stack(b);
	if (len > 1)
		swap_top(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	finalize_check(t_list *stack_a, t_list *stack_b)
{
	min_val_confirmation(&stack_a);
	freelist(stack_a);
	freelist(stack_b);
}
