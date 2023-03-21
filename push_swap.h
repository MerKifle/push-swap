/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:56:10 by Degef             #+#    #+#             */
/*   Updated: 2023/03/21 20:08:08 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_list
{
	int				data;
	int				sort_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	struct t_list	*next;
}					t_node;

//push_swap
void	push_swap(t_node **a);
void	swap(t_node *stack, char *str);

// utils
t_node	*lstlast(t_node *lst);
int		is_sorted(t_node *stack);
void	message(int nb);
void	create_linked_list(char **storage, t_node **a);

//free_allocated
void	free_array(char ***str);
void	free_linked_list(t_node **stack);

//validate_args
int		check_dup(char *str);
int		check_invalid_args(char *str);

// operations
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	rotate(t_node **stack, char *str, int cost);
void	reverse_rotate(t_node **stack, char *str, int cost);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);

// put sorting index
int		find_len(t_node *stack);
void	sort_int_array(int **tab, int size);
void	assign_index(int len, t_node **stack, int *sorted_list);
void	put_sorting_index(t_node **stack);

// count moves
int		count_forward_moves(t_node *stack, int point);
int		count_backward_moves(t_node *stack, int point);

//send_to_b
void	move_to_b(t_node **a, t_node **b);

//send_to_a
void	push_to_a(t_node **a, t_node **b);

//cost
void	find_cost(t_node **a, t_node **b);
int		find_cheapest(t_node **b);

#endif