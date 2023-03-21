/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 20:06:13 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, char *str)
{
	int	temp;
	int	temp2;

	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	temp2 = stack->sort_index;
	stack->sort_index = stack->next->sort_index;
	stack->next->sort_index = temp2;
	if (ft_strncmp(str, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(str, "sb", 2) == 0)
		write(1, "sb\n", 3);
}

static void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->sort_index;
	second = (*stack)->next->sort_index;
	third = (*stack)->next->next->sort_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third))
	{
		swap(*stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if ((first > second) && (first < third) && (second < third))
		swap(*stack, "sa");
	else if ((first < second) && (first > third))
		reverse_rotate(stack, "rra", -1);
	else if ((first > second) && (first > third) && (second < third))
		rotate(stack, "ra", 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		swap(*stack, "sa");
		reverse_rotate(stack, "rra", -1);
	}
}

static void	rearrange_a(t_node **stack, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = count_forward_moves(*stack, point);
	rra_size = count_backward_moves(*stack, point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		while (rra_size--)
			reverse_rotate(stack, "rra", -1);
	else
		while (ra_size--)
			rotate(stack, "ra", 1);
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

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		exit(0);
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) >= 4)
		move_to_b(a, &b);
	sort_three(a);
	push_to_a(a, &b);
	rearrange_a(a, 0);
	free_linked_list(&b);
	return ;
}

int	main(int argc, char **argv)
{
	t_node	*a;
	int		i;
	char	*storage;
	char	*str;

	if (argc >= 2)
	{
		i = 1;
		if (!argv[i][0])
			message(0);
		storage = NULL;
		while (argv[i])
		{
			storage = ft_strjoin(storage, argv[i++]);
			storage = ft_strjoin(storage, " ");
		}
		if (!check_invalid_args(storage) || !check_dup(storage))
			message(0);
		a = NULL;
		create_linked_list(&storage, &a);
		put_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}	
	return (0);
}

		// while (a)
		// {
		// 	printf("%d : %d\n", a->data, a->sort_index);
		// 	a = a->next;
		// }