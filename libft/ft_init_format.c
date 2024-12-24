/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:13:55 by anmakaro          #+#    #+#             */
/*   Updated: 2023/11/02 12:13:56 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_format(va_list args, const char format)
{
	int	cumulative_length;

	cumulative_length = 0;
	if (format == 'c')
		cumulative_length
			+= ft_print_char(va_arg(args, int));
	else if (format == 's')
		cumulative_length
			+= ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		cumulative_length
			+= ft_print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		cumulative_length
			+= ft_print_decimal_integer(va_arg(args, int));
	else if (format == 'u')
		cumulative_length
			+= ft_print_unsigned_decimal(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		cumulative_length
			+= ft_print_hexadecimal(va_arg(args, unsigned int), format);
	else if (format == '%')
		cumulative_length
			+= ft_print_percent_sign();
	return (cumulative_length);
}
