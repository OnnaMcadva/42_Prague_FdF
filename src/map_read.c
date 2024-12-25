/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:20:16 by annavm            #+#    #+#             */
/*   Updated: 2024/12/25 18:20:31 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

static char	*realloc_map(char *map, size_t *map_size)
{
	size_t	old_size;

	old_size = *map_size;
	*map_size *= 2;
	map = ft_realloc(map, old_size, *map_size * sizeof(char));
	alloc_null(map, NULL);
	return (map);
}

char	*map_read(int fd)
{
	char		*buffer;
	char		*map;
	int			byte_read;
	size_t		map_size;
	size_t		total_bytes;

	map_size = UNIT_READ;
	total_bytes = 0;
	map = malloc(map_size * sizeof(char));
	alloc_null(map, NULL);
	buffer = malloc(UNIT_READ * sizeof(char));
	alloc_null(buffer, map);
	byte_read = read(fd, buffer, UNIT_READ);
	while (byte_read > 0)
	{
		if (total_bytes + byte_read > map_size)
			map = realloc_map(map, &map_size);
		ft_memcpy(map + total_bytes, buffer, byte_read);
		total_bytes += byte_read;
		byte_read = read(fd, buffer, UNIT_READ);
	}
	write(1, "\033[0;93m\t[ ✔ ]\tmap is reading\033[0m\n", 36);
	free(buffer);
	map[total_bytes] = '\0';
	return (map);
}

/*
static void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size < new_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

static char	*realloc_map(char *map, size_t *map_size)
{
	size_t	old_size;

	old_size = *map_size;
	*map_size *= 2;
	map = ft_realloc(map, old_size, *map_size * sizeof(char));
	alloc_null(map, NULL);
	return (map);
}

char	*map_read(int fd)
{
	char		*buffer;
	char		*map;
	int			byte_read;
	size_t		map_size;
	size_t		total_bytes;

	map_size = UNIT_READ;
	total_bytes = 0;
	map = malloc(map_size * sizeof(char));
	alloc_null(map, NULL);
	buffer = malloc(UNIT_READ * sizeof(char));
	alloc_null(buffer, map);
	byte_read = read(fd, buffer, UNIT_READ);
	while (byte_read > 0)
	{
		if (total_bytes + byte_read > map_size)
			map = realloc_map(map, &map_size);
		ft_memcpy(map + total_bytes, buffer, byte_read);
		total_bytes += byte_read;
		byte_read = read(fd, buffer, UNIT_READ);
	}
	write(1, "\033[0;93m\t[ ✔ ]\tmap is reading\033[0m\n", 36);
	free(buffer);
	map[total_bytes] = '\0';
	return (map);
}
*/