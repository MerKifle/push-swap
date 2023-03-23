/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:10:10 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/21 19:53:40 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
find_midpt:
it will calculate the sum of the sorted index of the stack 
and will divide it by the largest index + 1.

if the remider is 0 
	 mid_point = sum/ i;
else 
 mid_point = (sum/ i) + 1;
eg: input = -1 8 4 7 2, 
	and thier indexes after sorting them will be 0, 4, 2, 3, 1
	so sum = 10, i = 4 (largest index) + 1 = 5;
	mid_point = 10 / 5 = 2
	if i is 3, it should be 10 / 
*/
static int	find_midpt(t_node *stack)
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

static void	fill_b(t_node **a, t_node **b, int *total_nodes_to_move,
			int *mid_point)
{
	int	i;

	i = ((*total_nodes_to_move) / 2 + 1);
	while (i > 0)
	{
		if ((*a)->sort_index < (*mid_point))
		{
			push(b, a, "pb");
			i--;
			(*total_nodes_to_move)--;
		}
		else if ((lstlast(*a)->sort_index < (*mid_point)))
		{
			reverse_rotate(a, "rra", -1);
			push(b, a, "pb");
			i--;
			(*total_nodes_to_move)--;
		}
		else
			rotate(a, "ra", 1);
	}
}

/*
move_to_b:
	except three elemens, it will move all the rest from stack a to b
	total_nodes_to_go: is the total num of nodes that will move to b 
	
*/
void	move_to_b(t_node **a, t_node **b)
{
	int	total_nodes_to_go;
	int	mid_point;

	total_nodes_to_go = find_len(*a) - 3;
	while (total_nodes_to_go > 0)
	{
		mid_point = find_midpt(*a);
		fill_b(a, b, &total_nodes_to_go, &mid_point);
	}
}
