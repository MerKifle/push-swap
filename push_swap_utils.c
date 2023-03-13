/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:35:17 by Degef             #+#    #+#             */
/*   Updated: 2023/03/13 21:09:04 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	message(int nb)
{
	(void)nb;
	write(2, "Error\n", 6);
	// else if (nb)
	// 	write(1, "OK\n", 3);
	exit(0);
}

// int	check_arguments(char *argv)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	while (argv[i])
// 	{	if (argv[i])
// 		if (argv[i] < '0' || argv[i] > '9')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	find_dup(t_node *a)
// {
// 	t_node	*next;

// 	while (a)
// 	{
// 		next = a->next;
// 		while (next)
// 		{
// 			if (a->data == next->data)
// 				return (1);
// 			next = next->next;
// 		}
// 		a = a->next;
// 	}
// 	return (0);
// }


