/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:11 by mkiflema          #+#    #+#             */
/*   Updated: 2023/01/13 18:29:11 by mkiflema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' '
			|| (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}	
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	while (nptr[i] != '\0' && !(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	return (sign * result);
}

// #include <stdio.h>

// int main()
// {
// 	char *str ="-0001";
// 	printf("%d", atoi(str));
// 	printf("\n%d", ft_atoi(str));
// }