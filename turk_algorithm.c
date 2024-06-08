/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:55:40 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 23:21:24 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a_strategy(t_list **stack_a, t_list **stack_b,
		int len_stack_a, int len_stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	calc_index_node (stack_a);
	calc_index_node (stack_b);
	calc_target_node_b (stack_a, stack_b, len_stack_a);
	calc_pushcost_to_a (stack_a, stack_b, len_stack_a, len_stack_b);
	push_decision_to_a (stack_a, stack_b, len_stack_a, len_stack_b);
}

void	push_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = count_stack(stack_a);
	len_stack_b = count_stack(stack_b);
	if (len_stack_b == 0)
		return ;
	while (len_stack_b > 0)
	{
		push_to_a_strategy (stack_a, stack_b, len_stack_a, len_stack_b);
		len_stack_a = count_stack (stack_a);
		len_stack_b = count_stack (stack_b);
	}
}

void	push_to_b_strategy(t_list **stack_a, t_list **stack_b, int len_stack_a,
				int len_stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	calc_index_node (stack_a);
	calc_index_node (stack_b);
	calc_target_node_a (stack_a, stack_b, len_stack_b);
	calc_pushcost_to_b (stack_a, stack_b, len_stack_a, len_stack_b);
	push_decision_to_b (stack_a, stack_b, len_stack_a, len_stack_b);
}

void	push_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	len_stack_a;
	int	len_stack_b;
	int	min_stack_b;
	int	max_stack_b;

	len_stack_b = count_stack (stack_b);
	if (len_stack_b == 0)
		pb(stack_a, stack_b);
	len_stack_a = count_stack (stack_a);
	len_stack_b = count_stack (stack_b);
	while (len_stack_a > 5)
	{
		push_to_b_strategy (stack_a, stack_b, len_stack_a, len_stack_b);
		len_stack_a = count_stack (stack_a);
		len_stack_b = count_stack (stack_b);
	}
}

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	push_to_stack_b (stack_a, stack_b);
	five_sorting (stack_a, stack_b);
	push_back_to_stack_a (stack_a, stack_b);
}
