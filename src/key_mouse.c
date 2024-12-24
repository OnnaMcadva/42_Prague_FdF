/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:12:59 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 02:06:47 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (fdf->keys.b_mouse_l)
	{
		fdf->map.src.axis[X] -= ((int)fdf->keys.lclick_l.axis[X] - x);
		fdf->map.src.axis[Y] -= ((int)fdf->keys.lclick_l.axis[Y] - y);
		fdf->map.src.axis[Z] = 0;
		fdf->keys.lclick_l.axis[X] = x;
		fdf->keys.lclick_l.axis[Y] = y;
		map_render(fdf, FREE);
	}
	return (0);
}

int	mouse_rele(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == 1)
		fdf->keys.b_mouse_l = 0;
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 1)
	{
		fdf->keys.b_mouse_l = 1;
		fdf->keys.lclick_l.axis[X] = x;
		fdf->keys.lclick_l.axis[Y] = y;
	}
	if (button == 5)
	{
		if (fdf->map.scale > 2)
			fdf->map.scale = fdf->map.scale / 1.2;
	}
	if (button == 4)
		fdf->map.scale = fdf->map.scale * 1.2;
	map_render(fdf, FREE);
	return (0);
}
