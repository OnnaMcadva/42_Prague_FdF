/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:10:02 by annavm            #+#    #+#             */
/*   Updated: 2024/12/22 01:38:42 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdigit_and_val(char c, int *val)
{
	if (c >= '0' && c <= '9')
	{
		*val = c - '0';
		return (1);
	}
	if (c >= 'a' && c <= 'f')
	{
		*val = c - 'a' + 10;
		return (1);
	}
	if (c >= 'A' && c <= 'F')
	{
		*val = c - 'A' + 10;
		return (1);
	}
	return (0);
}

static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	check_overflow(long result, int val, int base)
{
	if (result > (LONG_MAX - val) / base)
		return (1);
	return (0);
}

long int	ft_strtol(const char *str, int base)
{
	long	result;
	int		sign;
	int		val;

	result = 0;
	sign = 1;
	str = skip_whitespace(str);
	sign = parse_sign(&str);
	while (ft_isdigit_and_val(*str, &val))
	{
		if (check_overflow(result, val, base))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * base + val;
		str++;
	}
	return (result * sign);
}
