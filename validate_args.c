/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:29:20 by mkiflema          #+#    #+#             */
/*   Updated: 2023/03/11 20:12:00 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char *str)
{
	char	**storage;
	int		i;
	int		j;

	i = 0;
	j = 0;
	storage = ft_split(str, ' ');
	while (storage[i])
	{
		j = i + 1;
		while (storage[j])
		{
			if (ft_strncmp(storage[i], storage[j], ft_strlen(storage[i])) == 0)
				return (0);
			j++;
		}
		i++;
	}
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

int	check_invalid_args(char *str)
{
	int		i;
	char	**storage;

	i = 0;
	while (str[i])
	{
		if (is_valid(str[i]))
			i++;
		else
			return (0);
	}
	storage = ft_split(str, ' ');
	while (*storage)
	{
		if (!ft_strncmp(*storage, "0", 1))
			storage++;
		else
		{
			if (!ft_atoi(*storage))
				return (0);
			storage++;
		}
	}
	return (1);
}
