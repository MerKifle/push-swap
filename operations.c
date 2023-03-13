/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:41:47 by Degef             #+#    #+#             */
/*   Updated: 2023/03/13 20:14:16 by Degef            ###   ########.fr       */
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
	temp2 =  stack->sort_index;
	stack->sort_index = stack->next->sort_index;
	stack->next->sort_index = temp2;
	if (ft_strncmp(str, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(str, "sb", 2) == 0)
		write(1, "sb\n", 3);
}

void	push_a(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*new_node;
	t_node	*update_node;
	int		temp;
	int		temp2;
	int		mid_point;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	mid_point = find_midpoint(*stack_2);
	update_node = *stack_2;
	while ((*stack_2)->next != NULL && find_len(*stack_2) > 2)
	{
		if ((*stack_2)->data < mid_point)
		{
			temp = (*stack_2)->data;
			temp2 = (*stack_2)->sort_index;
			new_node = malloc(sizeof(t_node));
			if (!new_node)
				return ;
			new_node->data = temp;
			new_node->sort_index = temp2;
			new_node->next = *stack_1;
			*stack_1 = new_node;
			*stack_2 = update_node;
		}
		*stack_2 = (*stack_2)->next;
	}
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}

void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*new_node;
	int		temp;
	int		temp2;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = (*stack_2)->data;
	temp2 = (*stack_2)->sort_index;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = temp;
	new_node->sort_index = temp2; 
	new_node->next = *stack_1;
	*stack_1 = new_node;
	*stack_2 = (*stack_2)->next;
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}

void	rotate(t_node **stack, char *str)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
    temp = malloc(sizeof(t_node));
    if (!temp)
        return ;
    temp->data = (*stack)->data;
	temp->sort_index = (*stack)->sort_index;
    temp->next = NULL;
	(*stack) = (*stack)->next;
    lstlast((*stack))->next = temp;
    // free(temp);
	if (ft_strncmp(str, "ra", 2) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(str, "rb", 2) == 0)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_node **stack, char *str)
{
	t_node	*temp;
	t_node	*looping;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = lstlast(*stack);
	looping = *stack;
	while (looping->next != NULL)
	{
		if (looping->next->data == temp->data)
		{
			looping->next = NULL;
			break ;
		}
		looping = looping->next;
	}
	temp->next = *stack;
	*stack = temp;
	if (ft_strncmp(str, "rra", 2) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(str, "rrb", 2) == 0)
		write(1, "rrb\n", 4);
}
