/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/15 19:23:22 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rearrange_a(t_node **stack, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = count_forward_moves(*stack, point);
	rra_size = count_backward_moves(*stack, point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		while (rra_size--)
			reverse_rotate(stack, "rra");
	else
		while (ra_size--)
			rotate(stack, "ra");
}

void	adjust_a(t_node **a, t_node **b)
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
	rearrange_a(a, target);
}

void	free_linked_list(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = (*stack);
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
		free(temp2);
	}
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		exit(0);
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else
	{
		while (find_len(*a) > 2)
		{	
			push(&b, a, "pb");
		}
	}
	while (b)
	{
		adjust_a(a, &b);
		push(a, &b, "pa");
	}
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
		// while (a)
		// {
		// 	printf("%d : %d\n", a->data, a->sort_index);
		// 	a = a->next;
		// }
		free_linked_list(&a);
	}	
	return (0);
}
