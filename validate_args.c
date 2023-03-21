/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:29:20 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/21 19:54:58 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char *str)
{
	char	**storage;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	storage = ft_split(str, ' ');
	while (storage[i])
	{
		j = i + 1;
		while (storage[j])
		{
			len = ft_strlen(storage[i]);
			if (ft_strlen(storage[j]) > ft_strlen(storage[i]))
				len = ft_strlen(storage[j]);
			if (ft_strncmp(storage[i], storage[j], len) == 0)
				return (0);
			j++;
		}
		i++;
	}
	free_array(&storage);
	return (1);
}

static int	is_valid(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || (c >= '0' && c <= '9')
		|| c == '-' || c == '+')
		return (1);
	else
		return (0);
}

static int	check_if_num(char *str)
{
	if (!ft_strncmp(str, "0", 1))
		return (0);
	else
	{
		if (!ft_atoi(str))
			return (1);
		return (0);
	}
}

static int	check_zeros_leading_dup(char **storage, int len)
{
	int		i;
	int		*array_int;
	int		j;

	i = -1;
	array_int = malloc(len * sizeof(int));
	while (++i < len)
		array_int[i] = ft_atoi(storage[i]);
	i = 0;
	while (i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			if (array_int[i] == array_int[j])
				return (0);
			j++;
		}
		i++;
	}
	free(array_int);
	free_array(&storage);
	return (1);
}

int	check_invalid_args(char *str)
{
	int		i;
	char	**storage;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_valid(str[i]))
			i++;
		else
			return (0);
	}
	i = 0;
	storage = ft_split(str, ' ');
	while (storage[i])
	{
		if (check_if_num(storage[i]))
			return (0);
		i++;
	}
	if (!check_zeros_leading_dup(storage, i))
		return (0);
	return (1);
}
