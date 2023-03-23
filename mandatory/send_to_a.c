/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:16:52 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/22 21:20:58 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
adjust:
	it makes an appoperiate adjustment to move one element from
	b to a
	if cost_a and cost_b < 0
		apply rrr
	if cost_a and cost_b > 0	
		apply rr
	etc...
	e.g:
		5
		6		7
		8		3
		1		0
		a		b
	indexes of (0, 1, 3, 5, 6, 7  8) are 0, 1, 2, 3, 4, 5, 6
	
	if the cheapest cost is for element 0
	 	cost_a = -1, cost_b = -1 (-ve indicates for direction, not value)
	 	hence, the required operation will be rrr
	
*/

static void	adjust(t_node *temp, t_node **a, t_node **b)
{
	if ((temp->cost_a < 0) && (temp->cost_b < 0))
		reverse_rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if ((temp->cost_a > 0) && (temp->cost_b > 0))
		rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if (temp->cost_b > 0 && temp->cost_a < 0)
	{
		rotate(b, "rb", temp->cost_b);
		reverse_rotate(a, "rra", temp->cost_a);
	}
	else if (temp->cost_b < 0 && temp->cost_a > 0)
	{
		reverse_rotate(b, "rrb", temp->cost_b);
		rotate(a, "ra", temp->cost_a);
	}
	else if (temp->cost_b == 0 && temp->cost_a > 0)
		rotate(a, "ra", temp->cost_a);
	else if (temp->cost_b == 0 && temp->cost_a < 0)
		reverse_rotate(a, "rra", temp->cost_a);
	else if (temp->cost_b > 0 && temp->cost_a == 0)
		rotate(b, "rb", temp->cost_b);
	else if (temp->cost_b < 0 && temp->cost_a == 0)
		reverse_rotate(b, "rrb", temp->cost_b);
}

/*
assign_position:
	this function assign current postion for all
	elements of a and b
	 e.g:
		1 (0)	
		5 (1)   3 (0)
		8 (2)	0 (1)
		a		b
	in braces are postion for each elements
	
	if one of the element of b moved to b, 
	the postion for both stacks will update
*/

static void	assign_position(t_node **a, t_node **b)
{
	int		i;
	t_node	*temp1;
	t_node	*temp2;

	i = 0;
	temp1 = *a;
	temp2 = *b;
	while (temp1)
	{
		temp1->pos = i++;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp2)
	{
		temp2->pos = i++;
		temp2 = temp2->next;
	}
}

/*
push_to_a:
it gets the element with cheapest cost using the its postion in b

it pushes all the elements of b to a after approperiate adjusment 
*/

void	push_to_a(t_node **a, t_node **b)
{
	int		cheapest_pos;
	t_node	*temp;

	while (*b)
	{
		assign_position(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest(b);
		temp = *b;
		while (temp->pos != cheapest_pos)
			temp = temp->next;
		adjust(temp, a, b);
		push(a, b, "pa");
	}
}
