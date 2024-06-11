/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_util_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:53:14 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 22:53:16 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	post_operation(t_list **stack_a, t_list **stack_b, int index_stack_a,
					int index_stack_b)
{
	int		len_stack_a;
	int		len_stack_b;
	bool	above_mid_stack_a;
	bool	above_mid_stack_b;

	len_stack_a = count_stack(stack_a);
	len_stack_b = count_stack(stack_b);
	above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
	above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
	swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
	swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
}

void	ss_rr(t_list **stack_a, t_list **stack_b,
int index_stack_a, int index_stack_b)
{
	if (index_stack_a == 1 && index_stack_b == 1)
		ss(stack_a, stack_b);
	else
		rr(stack_a, stack_b);
	index_stack_a--;
	index_stack_b--;
}

// Joint instructions(ss, rr, rrr);
void	joint_instructions(t_list **stack_a, t_list **stack_b,
						int index_stack_a, int index_stack_b)
{
	int		len_stack_a;
	int		len_stack_b;
	bool	above_mid_stack_a;
	bool	above_mid_stack_b;

	len_stack_a = count_stack(stack_a);
	len_stack_b = count_stack(stack_b);
	above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
	above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
	while ((0 < index_stack_a && index_stack_a < len_stack_a) && \
	(0 < index_stack_b && index_stack_b < len_stack_b))
	{
		if (above_mid_stack_a && above_mid_stack_b)
		{
			rrr(stack_a, stack_b);
			index_stack_a++;
			index_stack_b++;
		}
		else
		{
			ss_rr(stack_a, stack_b, index_stack_a, index_stack_b);
		}
	}
	post_operation(stack_a, stack_b, index_stack_a, index_stack_b);
}

void	push_decision_to_a(t_list **stack_a, t_list **stack_b,
						int len_stack_a, int len_stack_b)
{
	int		target;
	int		index_stack_a;
	int		index_stack_b;
	bool	above_mid_stack_a;
	bool	above_mid_stack_b;

	target = calc_min_pushcost(stack_b, &index_stack_b);
	index_stack_a = find_index_of_target(stack_a, target, len_stack_a);
	above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
	above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
	if (above_mid_stack_a && above_mid_stack_b)
	{
		joint_instructions(stack_a, stack_b, index_stack_a, index_stack_b);
	}
	else
	{
		swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
		swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
	}
	pa(stack_a, stack_b);
}

void	push_decision_to_b(t_list **stack_a, t_list **stack_b,
						int len_stack_a, int len_stack_b)
{
	int		target;
	int		index_stack_a;
	int		index_stack_b;
	bool	above_mid_stack_a;
	bool	above_mid_stack_b;

	target = calc_min_pushcost(stack_a, &index_stack_a);
	index_stack_b = find_index_of_target(stack_b, target, len_stack_b);
	above_mid_stack_b = chk_mid(find_mid_of_stack(len_stack_b), index_stack_b);
	above_mid_stack_a = chk_mid(find_mid_of_stack(len_stack_a), index_stack_a);
	if (above_mid_stack_a && above_mid_stack_b)
	{
		joint_instructions(stack_a, stack_b, index_stack_a, index_stack_b);
	}
	else
	{
		swap_stack_a(stack_a, index_stack_a, len_stack_a, above_mid_stack_a);
		swap_stack_b(stack_b, index_stack_b, len_stack_b, above_mid_stack_b);
	}
	pb(stack_a, stack_b);
}
