/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:53:44 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:53:45 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	int	num1;
	int	len;

	len = count_stack(b);
	if (len > 0)
	{
		num1 = pop(b);
		push(a, num1);
	}
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	int	num1;
	int	len;

	len = count_stack(a);
	if (len > 0)
	{
		num1 = pop(a);
		push(b, num1);
	}
	ft_printf("pb\n");
}

void	ra(t_list **a)
{
	int	num;
	int	len;

	len = count_stack(a);
	if (len > 0)
	{
		num = pop(a);
		insert_last(a, num);
	}
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	int	num;
	int	len;

	len = count_stack(b);
	if (len > 0)
	{
		num = pop(b);
		insert_last(b, num);
	}
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
