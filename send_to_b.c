/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:44:11 by Degef             #+#    #+#             */
/*   Updated: 2023/03/18 18:42:00 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpt(t_node *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (stack)
	{
		sum += stack->sort_index;
		i++;
		stack = stack->next;
	}
	if (sum % i == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

void	send_to_b_if_less_200(t_node **a, t_node **b)
{
	int	total_nodes_to_go;
	int	mid_pt;
	int	i;

	total_nodes_to_go = find_len(*a) - 3;
	while (total_nodes_to_go > 0)
	{
		mid_pt = find_midpt(*a);
		i = ((total_nodes_to_go / 2) + 1);
		while (i > 0)
		{
			if ((*a)->sort_index < mid_pt)
			{
				push(b, a, "pb");
				i--;
				total_nodes_to_go--;
			}
			else if ((*a)->next->sort_index < mid_pt)
			{
				rotate(a, "ra");
				push(b, a, "pb");
				i--;
				total_nodes_to_go--;
			}
			else if ((lstlast(*a)->sort_index < mid_pt))
			{
				reverse_rotate(a, "rra");
				push(b, a, "pb");
				i--;
				total_nodes_to_go--;
			}
			else
				rotate(a, "ra");
		}
	}
}

void	send_chunk(t_node **stack1, t_node **stack2,
					int chunk, int *total_nodes_to_go)
{
	t_node	*temp;

	temp = *stack1;
	while (temp)
	{
		if (temp->sort_index < chunk)
		{
			rearrange_a(stack1, temp->sort_index);
			push(stack2, stack1, "pb");
			temp = *stack1;
			total_nodes_to_go--;
		}
		temp = temp->next;
	}
}

void	send_to_b_if_more_200(t_node **a, t_node **b)
{
	int	total_nodes_to_go;
	int	chunk;
	int	i;

	total_nodes_to_go = find_len(*a) - 3;
	chunk = total_nodes_to_go / 13;
	i = chunk;
	while (total_nodes_to_go > chunk)
	{
		send_chunk(a, b, chunk, &total_nodes_to_go);
		chunk += i;
	}
	if (total_nodes_to_go < chunk && total_nodes_to_go > 0)
	{
		send_to_b_if_less_200(a, b);
	}
}
