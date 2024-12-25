/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:37:27 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 15:54:11 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	map_name(const char *s)
{
	const char	*prefix;
	const char	*suffix;
	size_t		s_len;
	size_t		prefix_len;
	size_t		suffix_len;

	prefix = "maps/";
	suffix = ".fdf";
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	prefix_len = ft_strlen(prefix);
	suffix_len = ft_strlen(suffix);
	if (s_len < prefix_len + suffix_len)
		return (0);
	if (ft_strncmp(s, prefix, prefix_len) != 0)
		return (0);
	if (ft_strcmp(s + s_len - suffix_len, suffix) != 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2 || !map_name(argv[1]))
		goodbye(IS_NAME);
	map_handle(&fdf.map, argv[1]);
	win_handle(&fdf);
	if (map_render(&fdf, FIT) < 0)
		goodbye(ERR_MAP);
	setup_hooks(&fdf);
	mlx_loop(fdf.wndw.mlx);
	mlx_do_key_autorepeaton(fdf.wndw.mlx);
	free (fdf.map.points);
	free (fdf.map.memory);
	return (0);
}
