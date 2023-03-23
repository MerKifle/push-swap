/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:29:20 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/23 18:20:56 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char *str)
{
	char	**storage;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	storage = ft_split(str, ' ');
	while (storage[++i])
	{
		j = i;
		while (storage[++j])
		{
			len = ft_strlen(storage[i]);
			if (ft_strlen(storage[j]) > ft_strlen(storage[i]))
				len = ft_strlen(storage[j]);
			if (ft_strncmp(storage[i], storage[j], len) == 0)
			{
				free_array(&storage);
				return (0);
			}
		}
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
	int	i;
	int	post;
	int	neg;
	int	isnotnum;

	i = -1;
	isnotnum = 1;
	while (str[++i])
		if (i > 1 && !(str[i] >= '0' && str[i] <= '9'))
			isnotnum = 0;
	post = (str[0] == '+' && str[1] == '0');
	neg = (str[0] == '-' && str[1] == '0');
	i = ft_strlen(str);
	if (isnotnum != 0 && (neg || post))
		return (1);
	else if (!ft_strncmp(str, "0", i))
		return (1);
	else
	{
		if (!ft_atoi(str))
			return (0);
		return (1);
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
	i = -1;
	while (++i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			if (array_int[i] == array_int[j])
			{
				free(array_int);
				return (0);
			}
			j++;
		}
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
		if (!check_if_num(storage[i]))
			return (free_array(&storage));
		i++;
	}
	if (!check_zeros_leading_dup(storage, i))
		return (free_array(&storage));
	return (1);
}
