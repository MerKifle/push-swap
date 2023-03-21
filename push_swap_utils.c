/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:35:17 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 19:51:10 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_linked_list(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			message(0);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->sort_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lstlast(*a)->next = nod;
		i++;
	}
	free_array(&str);
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
	exit(1);
}
