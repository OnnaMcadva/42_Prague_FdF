/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_prim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:24:25 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 16:11:54 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/* "floating-point step line algorithm" */
int	draw_line(t_fdf *fdf, t_vrtx start, t_vrtx end)
{
	t_vrtx	delta;
	t_vrtx	pixel;
	int		pixels;
	int		len;

	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
		return (0);
	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	delta.axis[X] /= pixels;
	delta.axis[Y] /= pixels;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	while (pixels > 0)
	{
		pixel.clr = gradient(start.clr, end.clr, len, len - pixels);
		put_pixel(fdf, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (1);
}

void	contorno_line(t_vrtx *point, t_fdf *fdf, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int)fdf->map.lims.axis[X])
	{
		x_end = i + density;
		if (x_end >= (int)fdf->map.lims.axis[X])
			x_end = (int)fdf->map.lims.axis[X] - 1;
		y_end = i + (int)fdf->map.lims.axis[X] * density;
		if (point[i].paint)
		{
			draw_line(fdf, point[i], point[x_end]);
			if (line + density < (int)fdf->map.lims.axis[Y])
				draw_line(fdf, point[i], point[y_end]);
		}
		i += density;
	}
}

void	draw_contorno_frame(t_fdf *fdf, t_vrtx *cont)
{
	int	i;
	int	density;

	density = 8 / fdf->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < fdf->map.len)
	{
		contorno_line (&cont[i], fdf, density, i / fdf->map.lims.axis[X]);
		i = i + fdf->map.lims.axis[X] * density;
	}
}

static void	dot_util(t_fdf *fdf, t_vrtx pixel, t_vrtx point, int coord)
{
	int	i;

	i = point.axis[X];
	while (i <= point.axis[X] + coord)
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] + coord;
		put_pixel(fdf, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] - coord;
		put_pixel(fdf, pixel);
		i++;
	}
}

void	draw_one_dot(t_fdf *fdf, t_vrtx point, int radius)
{
	int		axis[2];
	int		change[2];
	int		radius_error;
	t_vrtx	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.clr = point.clr;
	while (axis[X] >= axis[Y])
	{
		dot_util(fdf, pixel, point, axis[Y]);
		dot_util(fdf, pixel, point, axis[X]);
		axis[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			axis[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}
