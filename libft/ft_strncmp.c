/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:45:05 by annavm            #+#    #+#             */
/*   Updated: 2024/12/20 23:45:06 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*unc1;
	const unsigned char	*unc2;
	unsigned int		i;

	unc1 = (const unsigned char *)s1;
	unc2 = (const unsigned char *)s2;
	i = 0;
	while ((unc1[i] || unc2[i]) && i < n)
	{
		if (unc1[i] != unc2[i])
			return (unc1[i] - unc2[i]);
		i++;
	}
	return (0);
}
