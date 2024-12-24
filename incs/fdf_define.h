/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:46:16 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 19:43:37 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

# define M_PI 3.14159265358979323846
# define BUFFER_SIZE 1024
# define UNIT_READ 500000

# define WINX 1600
# define WINY 900

# define IS_NAME "\033[0;92mPut:\n\n./fdf maps/pylone.fdf\n./fdf \
maps/42.fdf\n./fdf maps/MGDS_WHOLE_WORLD_OCEAN0_M.fdf\n😸\n\033[0m"
# define ERR_OPEN		"\033[0;91mERR\033[0m opening the file"
# define MEM_ALL        "Memory allocation error"
# define ERR_MAP		"Map Error"
# define ERR_LINE		"\nError: nº of elements is different for each line"
# define MY_FILE		"\033[0;91mERR\033[0m: file is empty or wrong format"

# define X 0
# define Y 1
# define Z 2

# define THETA  0
# define RADIUS 1

# define RED 		0xc1272d
# define GREEN		0x33cc55
# define FUCHSIA 	0xff255c
# define BLUE		0x1B8EFA
# define SUPERBLUE	0x0000FF
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D
# define YELLOW     0xFFFF00

# define RED_N     0xFF0000
# define ORANGE  0xFF7F00
# define GREEN_N   0x00FF00
# define BLUE_N    0x0000FF
# define INDIGO  0x4B0082
# define VIOLET  0x8B00FF

# define DEFA_CLR		JAFFA
# define BOTTOM_CLR		BLUE
# define TOP_CLR		BRICK_RED
# define GROUND_CLR		SAFFRON
# define BACK_CLR		0x000033
# define MENU_CLR		0x000044
# define TEXT_CLR		0xFFFF00	
# define DJ_CLR		    0x00FF00
# define NUMBER_CLR		0xF3AF3D

# define MENU_WIDTH			350
# define ESPACIO_BORDE		50

# define FIT				1
# define FREE				0

# define CONTROL_BAR		80
# define DJ_BAR		        500
# define LINE_SIZE			40
# define MENU_TAB			65

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\x1B[0m"
# define SH_KRED	"\x1B[31m"
# define SH_KGRN	"\x1B[32m"
# define SH_KYEL	"\x1B[33m"
# define SH_KBLU	"\x1B[34m"
# define SH_KMAG	"\x1B[35m"
# define SH_KCYN	"\x1B[36m"
# define SH_KWHT	"\x1B[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

#endif
