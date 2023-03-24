/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/24 11:27:45 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, char *str)
{
	int	temp;
	int	temp2;

	if (!stack || !stack->next)
		return ;
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

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	else if (find_len(*a) == 2)
	{
		swap(*a, "sa");
		return ;
	}
	else if (find_len(*a) >= 4)
		move_to_b(a, &b);
	sort_three(a);
	if (b)
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

	if (argc >= 2)
	{
		i = 1;
		if (!argv[i][0])
			message(0);
		storage = NULL;
		while (argv[i])
		{
			if (argv[i][0] == '\0')
				free_first(&storage);
			storage = ft_strjoin(ft_strjoin(storage, argv[i++]), " ");
		}
		if (!check_invalid_args(storage) || !check_dup(storage))
			free_first(&storage);
		a = NULL;
		fill_a(&storage, &a);
		put_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}
	return (0);
}
