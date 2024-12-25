/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:01:56 by annavm            #+#    #+#             */
/*   Updated: 2024/12/25 18:13:54 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	base_color(t_map *map)
{
	map->clrs.backclr = BACK_CLR;
	map->clrs.menuclr = MENU_CLR;
	map->clrs.bottomclr = BOTTOM_CLR;
	map->clrs.groundclr = GROUND_CLR;
	map->clrs.topclr = TOP_CLR;
}

void	map_reset(t_map *map, int total)
{
	if (total)
	{
		map->len = 0;
		map->lims.axis[X] = 0;
		map->lims.axis[Y] = 0;
		map->lims.axis[Z] = 0;
		map->zmin = 0;
	}
	map->b_lines = 1;
	map->b_dots = 0;
	map->b_stars = 0;
	map->b_words = 0;
	map->scale = 1;
	map->zdivisor = 1;
	map->bend = 0;
	map->src.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->src.axis[Y] = WINY / 2;
	map->src.axis[Z] = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	base_color(map);
}

void	map_handle(t_map *map, char *path)
{
	int	fd;

	map_reset(map, 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		goodbye(ERR_OPEN);
	map->memory = map_read(fd);
	close (fd);
	map_size(map);
	map_points(map);
	map_color(map);
}
