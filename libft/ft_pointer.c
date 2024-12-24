/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:14:06 by anmakaro          #+#    #+#             */
/*   Updated: 2023/11/02 12:14:07 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	cumulative_length;

	cumulative_length = 0;
	if (ptr == 0)
		cumulative_length += write(1, "(nil)", 5);
	else
	{
		cumulative_length += write(1, "0x", 2);
		ft_putptr(ptr);
		cumulative_length += ft_ptrlen(ptr);
	}
	return (cumulative_length);
}
