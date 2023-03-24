/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:37:39 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/24 11:30:06 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

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

// utils
t_node	*lstlast(t_node *lst);
int		is_sorted(t_node *stack);
void	message(void);
void	fill_a(char **storage, t_node **a);

//validate_args
int		check_dup(char *str);
int		check_invalid_args(char *str);

// operations
void	swap(t_node *stack);
void	push(t_node **stack_1, t_node **stack_2);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

//free_allocated
int		free_array(char ***str);
void	free_linked_list(t_node **stack);
void	free_first(char **str);

#endif