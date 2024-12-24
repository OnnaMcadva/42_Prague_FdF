/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:40:08 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 16:36:39 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include <stdbool.h>

/* for map_color.c  */
typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}	t_rgb;

typedef struct s_vrtx
{
	float	axis[3];
	int		clr;
	int		hex_clr;
	bool	paint;
}	t_vrtx;

typedef struct m_clrs
{
	int	topclr;
	int	groundclr;
	int	bottomclr;
	int	backclr;
	int	menuclr;	
}	t_clrs;

typedef struct s_img
{
	void	*imgptr;
	char	*data;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_wndw
{
	void	*mlx;
	void	*win;
}	t_wndw;

typedef struct s_keys
{
	bool	b_mouse_l;
	bool	b_mouse_r;
	bool	b_keyctrl;
	t_vrtx	lclick_l;
}	t_keys;

typedef struct m_map
{
	t_vrtx		*points;
	t_vrtx		lims;
	t_vrtx		src;
	t_clrs		clrs;
	char		*memory;
	char		**lines;
	int			zmin;
	float		ang[3];
	float		zdivisor;
	float		scale;
	int			len;
	float		bend;
	int			renders;
	bool		b_lines;
	bool		b_dots;
	bool		b_stars;
	bool		b_words;
	double		performance;
	float		proportion;
	float		radius;
}	t_map;

typedef struct s_fdf
{
	t_wndw	wndw;
	t_img	img;
	t_map	map;
	t_keys	keys;
}	t_fdf;

#endif
