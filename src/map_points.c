/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:05:13 by annavm            #+#    #+#             */
/*   Updated: 2024/12/22 22:29:32 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	get_colors(char *line)
{
	char	**color;
	int		get_color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		get_color = ft_strtol(color[1] + 2, 16);
		free_mapy(color);
		return (get_color);
	}
	else
		return (0);
}

static int	is_vrtx(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

static int	get_points(char *line, t_map *map, int numline)
{
	char		**split;
	int			i;
	static int	p_indx = 0;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i] && split[i][0] != '\n')
	{
		if (!is_vrtx(&split[i][0]))
			goodbye(MY_FILE);
		map->points[p_indx].axis[Z] = ft_atoi(&split[i][0]);
		map->points[p_indx].axis[X] = i - map->lims.axis[X] / 2;
		map->points[p_indx].axis[Y] = numline - map->lims.axis[Y] / 2;
		map->points[p_indx].paint = 1;
		map->points[p_indx].clr = DEFA_CLR;
		map->points[p_indx].hex_clr = get_colors (split[i]);
		if (map->lims.axis[Z] < map->points[p_indx].axis[Z])
			map->lims.axis[Z] = map->points[p_indx].axis[Z];
		if (map->zmin > map->points[p_indx].axis[Z])
			map->zmin = map->points[p_indx].axis[Z];
		i++;
		p_indx++;
	}
	free_mapy(split);
	return (i);
}

void	map_points(t_map *map)
{
	int			i;
	char		*row;
	char		*last_row;
	static int	num_points = 0;
	static int	num_rows = 0;

	last_row = map->memory;
	row = NULL;
	i = 0;
	map->points = ft_calloc (map->len, sizeof(t_vrtx));
	while (++i)
	{
		if (map->memory[i] == '\n' || map->memory[i] == '\0')
		{
			free (row);
			row = ft_substr(last_row, 0, &map->memory[i] - last_row);
			last_row = &map->memory[i + 1];
			num_points += get_points(row, map, num_rows++);
			if (map->memory[i] == '\0')
				break ;
		}
	}
	free (row);
	ft_printf("\033[0;93m\r %d \t[ ✔ ]\tpoints readed\033[0m\n\n", num_points);
}
