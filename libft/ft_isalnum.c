/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:04:02 by anmakaro          #+#    #+#             */
/*   Updated: 2023/10/17 20:39:34 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int symba)
{
	if (('a' <= symba && symba <= 'z')
		|| ('A' <= symba && symba <= 'Z')
		|| ('0' <= symba && symba <= '9'))
		return (1);
	return (0);
}
