/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:35:17 by Degef             #+#    #+#             */
/*   Updated: 2023/03/14 16:30:29 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_linked_list(char *storage, t_node **a)
{
	t_node	*nod;
	int		num;
	char	**str;

	str = ft_split(storage, ' ');
	while (*str)
	{
		num = ft_atoi(*str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->sort_index = 0;
		if (*a)
			nod->next = (*a);
		(*a) = nod;
		str++;
	}
}

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
