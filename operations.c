/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:41:47 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 20:05:16 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*new_node;
	t_node	*temp;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp->next = *stack_1;
	*stack_1 = temp;
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}

void	rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		temp->next = NULL;
		lstlast((*stack))->next = temp;
		if (ft_strncmp(str, "ra", 2) == 0)
			write(1, "ra\n", 3);
		else if (ft_strncmp(str, "rb", 2) == 0)
			write(1, "rb\n", 3);
		cost--;
	}
}

void	reverse_rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;
	t_node	*looping;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (cost < 0)
	{
		temp = lstlast(*stack);
		looping = *stack;
		while (looping->next != NULL && looping->next->data != temp->data)
			looping = looping->next;
		looping->next = NULL;
		temp->next = *stack;
		*stack = temp;
		if (ft_strncmp(str, "rra", 3) == 0)
			write(1, "rra\n", 4);
		else if (ft_strncmp(str, "rrb", 3) == 0)
			write(1, "rrb\n", 4);
		cost++;
	}
}

void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(a, " ", -1);
		reverse_rotate(b, " ", -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	reverse_rotate(a, "rra", cost_a);
	reverse_rotate(b, "rrb", cost_b);
}

void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(a, " ", 1);
		rotate(b, " ", 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(a, "ra", cost_a);
	rotate(b, "rb", cost_b);
}
