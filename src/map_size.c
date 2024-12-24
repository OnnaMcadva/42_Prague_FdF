/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:10:04 by annavm            #+#    #+#             */
/*   Updated: 2024/12/22 22:38:23 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	update_dims(t_map *map, int num_elems)
{
	if (map->lims.axis[X] != 0 && map->lims.axis[X] != num_elems)
		goodbye(ERR_LINE);
	else
		map->lims.axis[X] = num_elems;
}

void	map_size(t_map *map)
{
	int	i;
	int	num_elems;

	i = 0;
	num_elems = 0;
	while (map->memory[i])
	{
		if (map->memory[i] == '\n')
		{
			if (map->memory[i + 1] == '\0')
				break ;
			map->lims.axis[Y]++;
			update_dims(map, num_elems);
			num_elems = 0;
		}
		else if (ft_isalnum(map->memory[i]) && (map->memory[i + 1] == ' ' \
			|| map->memory[i + 1] == '\n' || map->memory[i + 1] == '\0'))
			num_elems++;
		i++;
	}
	if (num_elems > 0)
		update_dims(map, num_elems);
	map->lims.axis[Y]++;
	map->len = map->lims.axis[X] * map->lims.axis[Y];
}
