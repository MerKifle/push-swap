/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:25:55 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/23 13:29:26 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
find_min_and_max:
	it finds the min index (smallest number) 
	and max index (largest num) of the elements available in stack a 
	e.g:
		1		
		5		3
		8		0
		a		b
	indexes of 0, 1, 3, 5, 8 are 0, 1, 2, 3, 4, respectively.
	hence; a_min = 1 and a_max = 4 
*/

static void	find_min_and_max(int *a_min, int *a_max, t_node *temp)
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

/*
check_min_and_max_diff:
	it finds the min +ve and max index difference of all current elements of a 
	and top element of b.
	e.g:
		1		
		5		3
		8		0
		a		b
	indexes of (0, 1, 3, 5, 8) are 0, 1, 2, 3, 4
	since the top element in b is 3 (index 2), it will calculate for that element
	diff_1 = 1 - 2 = -1; diff_2 = 3 - 2 = 1; diff_3 = 4 - 2 = 2
	hence max_diff = 2;

	since I want min postive diff, the initial value should be the Max Integer
	if there is a diff less than Max Int, min_diff will be updated
	else min +ve diff will be Max Int 
	for the above example, min_diff = 1;
*/

static void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
									t_node **a, t_node **b)
{
	t_node	*temp_a;
	int		next_diff;

	temp_a = *a;
	*max_diff = temp_a->sort_index - (*b)->sort_index;
	*min_pos_diff = INT_MAX;
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

/*
get_target_index:
	it returns the place (index) where element of b should be placed in stack a
	 from the above functions:
	min_postive_diff = 1;
	max_diff = 2;
	a_min = 1
	a_max = 4
	e.g:
		1		
		5		3
		8		0
		a		b
	indexes of (0, 1, 3, 5, 8) are 0, 1, 2, 3, 4
	how it works:
		if max diff is > 0:
			our target (postion of element 3 in a) = min_diff + index of 3
			target = 1 + 2 = 3; so, the place of element 3 in a is in the place
			 where an element with its index is 3, in this example the element is 5.
			 hence, five should be at top in order to move 3 from b to a
		else if max diff is < 0
		target is a_min because there is no -ve index
	Note: target = 3
*/

static int	get_target_index(t_node **a, t_node **b)
{
	int		min_pos_diff;
	int		max_diff;
	int		target;
	int		a_min;
	int		a_max;

	check_min_and_max_diff(&min_pos_diff, &max_diff, a, b);
	find_min_and_max(&a_min, &a_max, *a);
	if (max_diff > 0)
		target = min_pos_diff + (*b)->sort_index;
	else if (max_diff < 0)
		target = a_min;
	return (target);
}

/*

find_cost:
	
	it will calculate the cost of every element in b,
	 to bring it on the top of stack b and to adjust its place in a
	 the cost is updated whenevery element of b is sent to a
	 
	 lets use the above example;
	 target = 3;
	 e.g:
		1		
		5		3
		8		0
		a		b
	indexes of (0, 1, 3, 5, 8) are 0, 1, 2, 3, 4
	for element 3 in b; 
		cost_b = 0 (its postion), it means that it will no require any operation
		 to bring it at the top
		cost_a= ?
		I need to count the num of ra and rra operations to bring
		the target 5 with index 3, in this case at the top of a
		ra_count = 1
		rra_count = 2
		so, I should use ra operation to adjust it 
		before i push 3 with index 2 from b to a
	
	note: if cost_b > size_b / 2; cost_b = postion of 0 - size_b; 
		since its below the mid point, I should count from bottom to apply rra
	
	same procedure for element 0 too:
	
	Note: cost_a and cost_b will be -ve value 
	to indicate that the required operation is rra
*/
void	find_cost(t_node **a, t_node **b)
{
	int		size_b;
	t_node	*temp_b;
	int		back_moves;
	int		target_index;

	temp_b = *b;
	while (temp_b)
	{
		size_b = find_len(*b);
		target_index = get_target_index(a, &temp_b);
		back_moves = count_backward_moves(*a, target_index);
		temp_b->cost_b = temp_b->pos;
		if (temp_b->cost_b > size_b / 2)
			temp_b->cost_b = temp_b->pos - size_b;
		temp_b->cost_a = count_forward_moves(*a, target_index);
		if (back_moves < temp_b->cost_a)
			temp_b->cost_a = back_moves * -1;
		temp_b = temp_b->next;
	}
}

/*
find_cheapest:
	from the above function, every element of b has an updated cost
	
	hence, this function finds the cheapest sum of cost_a + cost_b
	and it returns its postion of an element 
	 e.g:
		1		
		5		3
		8		0
		a		b
	indexes of (0, 1, 3, 5, 8) are 0, 1, 2, 3, 4
	cost of 3 = cost_a + cost_b = 1 + 0;
	cost of 0 = 0 + 1;
	and the cheapest will return 
	
	fortunately, in this example, the cost for both elements are equal, 
	 so just take the first element as the cheapest 
	N.B: if either costs (a or b) are -ve, it should be multiply with -ve
	as -ve sign is just to indicate with required operation is reverse rotation 
*/
int	find_cheapest(t_node **b)
{
	int		cheapest;
	t_node	*temp;
	int		cost_a;
	int		cost_b;
	int		cheapest_pos;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		cost_a = temp->cost_a;
		if (cost_a < 0)
			cost_a = temp->cost_a * -1;
		cost_b = temp->cost_b;
		if (cost_b < 0)
			cost_b = temp->cost_b * -1;
		if (cheapest > (cost_a + cost_b))
		{
			cheapest = (cost_a + cost_b);
			cheapest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (cheapest_pos);
}
