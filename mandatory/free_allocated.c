/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:51:15 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/24 11:25:58 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	free_array(char ***str)
{
	int	i;

	i = 0;
	if (!(*str))
		return (0);
	while ((*str)[i])
		i++;
	while (i >= 0)
		free((*str)[i--]);
	free(*str);
	return (0);
}

void	free_first(char **str)
{
	free(*str);
	message(0);
}
