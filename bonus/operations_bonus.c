/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:41:47 by Degef             #+#    #+#             */
/*   Updated: 2023/03/23 19:03:48 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_node *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
}

void	push(t_node **stack_1, t_node **stack_2)
{
	t_node	*temp;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp->next = *stack_1;
	*stack_1 = temp;
}

void	rotate(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	lstlast((*stack))->next = temp;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*looping;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = lstlast(*stack);
	looping = *stack;
	while (looping->next != NULL && looping->next->data != temp->data)
		looping = looping->next;
	looping->next = NULL;
	temp->next = *stack;
	*stack = temp;
}
