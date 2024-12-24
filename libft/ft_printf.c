/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:14:11 by anmakaro          #+#    #+#             */
/*   Updated: 2023/11/02 12:14:12 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		cumulative_length;

	i = 0;
	cumulative_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cumulative_length += ft_init_format(args, str[i + 1]);
			i++;
		}
		else
			cumulative_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (cumulative_length);
}
