/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkomasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:22:07 by khkomasa          #+#    #+#             */
/*   Updated: 2024/06/06 23:19:44 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
0: not equal => dont sort
1: equal     =>      sorted
*/

#include "push_swap.h"

static int	array_comparison(int original[], int sorted[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (original[i] != sorted[i])
			return (0);
		i++;
	}
	return (1);
}

void	ascending_sort(int *num, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[j] < num[i])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

bool	chk_sorting(t_list **stack)
{
	t_list	*tmp;
	bool	is_sorted;
	int		len;
	int		*sorted_ptr;
	int		*original_ptr;

	tmp = *stack;
	len = count_stack (&tmp);
	original_ptr = malloc (sizeof(int) * len);
	sorted_ptr = malloc (sizeof(int) * len);
	if (original_ptr == NULL || sorted_ptr == NULL)
		return (-1);
	linked_list_to_arr (&tmp, original_ptr);
	ft_memmove (sorted_ptr, original_ptr, len * sizeof (int));
	ascending_sort (sorted_ptr, len);
	is_sorted = array_comparison(original_ptr, sorted_ptr, len);
	free (original_ptr);
	free (sorted_ptr);
	return (is_sorted);
}
