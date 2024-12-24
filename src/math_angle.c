/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:06:14 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 03:09:37 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	an_angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
		*ang = 360 + *ang;
	if (*ang >= 360)
		*ang = *ang - 360;
}

void	math_angle(int key, t_fdf *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.b_keyctrl)
		ang = 90;
	if (key == AR_DOWN)
		an_angle(&fdf->map.ang[X], ang);
	if (key == AR_UP)
		an_angle(&fdf->map.ang[X], -ang);
	if (key == AR_LEFT)
		an_angle(&fdf->map.ang[Y], ang);
	if (key == AR_RIGHT)
		an_angle(&fdf->map.ang[Y], -ang);
	if (key == Q)
		an_angle(&fdf->map.ang[Z], ang);
	if (key == W)
		an_angle(&fdf->map.ang[Z], -ang);
}
