/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:47 by Degef             #+#    #+#             */
/*   Updated: 2023/03/14 16:47:07 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_and_max(int *a_min, int *a_max, t_node *temp)
{
	*a_min = temp->sort_index;
	*a_max = temp->sort_index;
	while (temp->next != NULL)
	{
		if (*a_min > temp->next->sort_index)
			*a_min = temp->next->sort_index;
		if (*a_max < temp->next->sort_index)
			*a_max = temp->next->sort_index;
		temp = temp->next;
	}
}

void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
									t_node **a, t_node **b)
{
	t_node	*temp_a;
	int		next_diff;

	temp_a = *a;
	*max_diff = temp_a->sort_index - (*b)->sort_index;
	*min_pos_diff = 1000;
	if ((temp_a->sort_index - (*b)->sort_index) > 0)
		*min_pos_diff = (temp_a->sort_index - (*b)->sort_index);
	while (temp_a->next)
	{
		next_diff = temp_a->next->sort_index - (*b)->sort_index;
		if (*max_diff < next_diff)
			*max_diff = next_diff;
		if (next_diff > 0 && *min_pos_diff > next_diff)
			*min_pos_diff = next_diff;
		temp_a = temp_a->next;
	}
}