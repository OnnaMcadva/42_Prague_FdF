/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:26:42 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 19:08:46 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_dj(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->wndw.mlx, fdf->wndw.win, x, y, DJ_CLR, str);
}

void	draw_hotkeys_dj(t_fdf *fdf)
{
	int		line;

	line = DJ_BAR;
	print_dj(fdf, MENU_TAB, line, " Peace, Love & Unity ");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, "        ");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, "        P E A C E");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, "                     L O V E   <3");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, " U N I T Y                  Responsibility");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, "          R E S P E C T");
	line += LINE_SIZE;
	print_dj(fdf, MENU_TAB, line, "                         R A V E");
	line += LINE_SIZE;
}

void	print_str(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(fdf->wndw.mlx, fdf->wndw.win, x, y, TEXT_CLR, str);
}

static void	draw_hotkeys_menu(t_fdf *fdf)
{
	int	line;

	line = CONTROL_BAR;
	print_str(fdf, MENU_TAB, line, "E S C  --->  E X I T");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "P  --->  P A R A L L E L");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "I  --->  R E L I E V O");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "S C R O L L  --->  Z o o o M");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "L _M O U S E  --->  T R A N S L A T E");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Q E A D W S  --->  R O T A I T I O N");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "R / F  --->  R E SE T  /  F I T");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "2 / 3  --->  B l a c k   &   W h i t e");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "B / CTRL_B  --->  B E N D I N G");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "4 K L   --->  Be crazy  --->  PLURR");
	line += LINE_SIZE;
}

void	loading_bar(t_fdf *fdf)
{
	draw_hotkeys_menu(fdf);
	if (fdf->map.b_words)
		draw_hotkeys_dj(fdf);
}
