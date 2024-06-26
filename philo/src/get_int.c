/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:35:49 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/23 09:51:32 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Checks that the string complies with number format.
*/
static int	check_number_form(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] && ft_strchr(" \t\v\n\r\f", str[i]) != NULL)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign = 1;
	}
	if (!str[i] && sign)
		return (KO);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (KO);
		i++;
	}
	return (OK);
}

/*
Skips through whitespace and returns index of first non-whitespace character.
*/
static int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(" \t\v\n\r\f", str[i]) != NULL)
		i++;
	return (i);
}

/*
Coverts a string into a long int.
*/
static long int	ft_atol(const char *str)
{
	long	num;
	long	prev;
	int		i;
	int		sign;

	i = skip_whitespace(str);
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		prev = num;
		num = num * 10 + (long)str[i++] - '0';
		if (prev > num)
		{
			if (sign == 1)
				return (9223372036854775807);
			return (-9223372036854775807);
		}
	}
	return (sign * num);
}

/*
Converts a string to an integer and stores it in the given int pointer. 
Returns OK (0) if conversion was successful, KO (1) if it was not. This could 
be because the string doesn't comply with number format or the value was 
outside the integer range.
*/
int	get_int(int *dest, char *str)
{
	long int	n;

	if (check_number_form(str))
		return (KO);
	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
		return (KO);
	*dest = (int)n;
	return (OK);
}
