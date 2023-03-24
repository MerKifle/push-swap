/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:37:26 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/24 11:29:43 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rest_operations(t_node **a, t_node **b, char *operation, int len)
{
	if (ft_strncmp(operation, "ra", len) == 0)
		rotate(a);
	else if (ft_strncmp(operation, "rb", len) == 0)
		rotate(b);
	else if (ft_strncmp(operation, "rr", len) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(operation, "rra", len) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(operation, "rrb", len) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(operation, "rrr", len) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	do_operation(t_node **a, t_node **b, char *operation)
{
	int		len;

	len = ft_strlen(operation);
	if (ft_strncmp(operation, "sa", len) == 0)
		swap(*a);
	else if (ft_strncmp(operation, "sb", len) == 0)
		swap(*b);
	else if (ft_strncmp(operation, "ss", len) == 0)
	{
		swap(*a);
		swap(*b);
	}
	else if (ft_strncmp(operation, "pb", len) == 0)
		push(b, a);
	else if (ft_strncmp(operation, "pa", len) == 0)
		push(a, b);
	else
		rest_operations(a, b, operation, len);
}

void	read_user_input(t_node **a)
{
	char	*line;
	t_node	*b;

	line = " ";
	b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line)
			do_operation(a, &b, line);
		else
			break ;
		free(line);
	}
	if (is_sorted(*a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_linked_list(&b);
	free(line);
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
			message();
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
		read_user_input(&a);
		free_linked_list(&a);
	}	
	return (0);
}
