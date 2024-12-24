/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:39:05 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 19:50:27 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_dots(t_fdf *fdf, t_vrtx *project)
{
	int	i;

	i = 0;
	while (i < fdf->map.len)
	{
		if (project[i].paint)
			draw_one_dot(fdf, project[i], 1);
		i++;
	}
}

static int	limits(t_vrtx *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[X] < (MENU_WIDTH + ESPACIO_BORDE) || \
			points[i].axis[X] > (WINX - ESPACIO_BORDE))
			return (1);
		if (points[i].axis[Y] < ESPACIO_BORDE || \
			points[i].axis[Y] > (WINY - ESPACIO_BORDE))
			return (1);
		i++;
	}
	return (0);
}

static void	auto_fit(t_fdf *fdf, t_vrtx *project)
{
	fdf->map.src.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	fdf->map.src.axis[Y] = WINY / 2;
	fdf->map.src.axis[Z] = 0;
	fdf->map.scale = 1;
	copy_map(fdf->map.points, project, fdf->map.len);
	parse_map(fdf, project);
	while (!(limits(project, fdf->map.len)))
	{
		copy_map(fdf->map.points, project, fdf->map.len);
		parse_map(fdf, project);
		fdf->map.scale = fdf->map.scale + 0.2;
	}
}

void	drawing(t_fdf *fdf, t_vrtx *projec, int fit)
{
	if (fdf->map.b_stars)
		draw_stars(fdf);
	if (fit)
		auto_fit(fdf, projec);
	if (fdf->map.b_lines)
		draw_contorno_frame(fdf, projec);
	if (fdf->map.b_dots)
		draw_dots(fdf, projec);
}
