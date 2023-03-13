/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:35:05 by Degef             #+#    #+#             */
/*   Updated: 2023/03/13 21:15:55 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	count_forward_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_index != point)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_backward_moves(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->sort_index != point)
		stack = stack->next;
	// printf("point:%d \n",stack->sort_index);
	stack = stack->next;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i + 1);
}

void	rearrange_a(t_node **stack, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = count_forward_moves(*stack, point);
	rra_size = count_backward_moves(*stack, point);
	// printf("ra_size:%d \n", ra_size);
	// printf("rra_size:%d \n", rra_size);
	// printf("target:%d \n", point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		while (rra_size--)
			reverse_rotate(stack, "rra");
	else
		while (ra_size--)
			rotate(stack, "ra");
}

void	find_min_and_max(int *a_min, int *a_max, t_node *temp)
{
	*a_min = temp->sort_index;
	*a_max = temp->sort_index;
	while (temp->next != NULL)
	{
		if (*a_min > temp->next->sort_index)
			*a_min = temp->next->sort_index;
		if (*a_max < temp->next->sort_index)
			*a_max = temp->next->sort_index;
		temp = temp->next;
	}
}

void	check_min_and_max_diff(int *min_pos_diff, int *max_diff, t_node **a, t_node **b)
{
	t_node	*temp_a;
	int		next_diff;

	temp_a = *a;
	*max_diff = temp_a->sort_index - (*b)->sort_index;
	*min_pos_diff = 1000;
	if ((temp_a->sort_index - (*b)->sort_index) > 0)
		*min_pos_diff = (temp_a->sort_index - (*b)->sort_index);
	while (temp_a->next)
	{
		next_diff = temp_a->next->sort_index - (*b)->sort_index;
		if (*max_diff < next_diff)
			*max_diff = next_diff;
		if (next_diff > 0 && *min_pos_diff > next_diff)
			*min_pos_diff = next_diff;
		temp_a = temp_a->next;
	}
	// printf("min:%d \n max:%d \n", *min_pos_diff, *max_diff);
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
	// printf("min_pos_diff:%d \n", min_pos_diff);
	// printf("max_diff:%d \n", max_diff);


	if (max_diff > 0)
		target = min_pos_diff + (*b)->sort_index;
	else if (max_diff < 0)
		target = a_min;
	// printf("target:%d \n", target);
	rearrange_a(a, target);
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		message(1);
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
	// while (*a)
	// {
	// 	printf("%d : %d\n", , a->sort_index);
	// 	a = a->next;
	// }
	rearrange_a(a, 0);
	// while (b)
	// 	free(lstlast(b));
	free(b);
	return ;
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*nod;
	int		num;
	int		i;
	char	*storage;
	char	**str;

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
		str = ft_split(storage, ' ');
		// printf("%s", storage);
		i = 0;
		while (*str)
		{
			// num = atoi(argv[i++]);
			num = ft_atoi(*str);
			nod = malloc(sizeof(t_node));
			nod->data = num;
			nod->next = NULL;
			nod->sort_index = 0;
			if (a)
				nod->next = a;
			a = nod;
			str++;
		}
		// if (find_dup(a))
		// 	message(0);
		put_sorting_index(&a);
		push_swap(&a);
		free(a);
		// while (a)
		// {
		// 	// printf("%d : %d\n", a->data, a->sort_index);
		// 	// a = a->next;
		// 	free(lstlast(a));
		// }
	}	
	return (0);
}

