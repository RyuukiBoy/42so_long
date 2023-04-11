/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:44:39 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 16:01:27 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**copy_map_b(char **map, t_mapb *size)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (size->height + 1));
	while (i < size->height)
	{
		j = 0;
		new_map[i] = malloc(sizeof(char) * (size->width + 1));
		while (j < size->width)
		{
			if (rectangular_map_b(map) == 0 || check_items_b(map) == 0)
				invalid_map_b();
			new_map[i][j] = map[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}

void	flood_fill(char **map, t_mapb *size, int x, int y)
{
	if (map[y][x] == 'E')
	{
		if (size->items->exit == 0)
			size->items->exit++;
	}
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E' ||
		map[y][x] == 'B' || map[y][x] == 'G' || map[y][x] == 'R'
		|| map[y][x] == 'Y')
		return ;
	if (map[y][x] == 'C')
		size->items->count++;
	map[y][x] = 'X';
	flood_fill(map, size, x + 1, y);
	flood_fill(map, size, x - 1, y);
	flood_fill(map, size, x, y + 1);
	flood_fill(map, size, x, y - 1);
}

void	check_path_b(char **map, t_mapb *size)
{
	char	**new_map;

	new_map = copy_map_b(map, size);
	flood_fill(new_map, size, size->player_dir->y, size->player_dir->x);
	if (size->items->exit == 0)
		roadblock_msg_b();
	if (size->items->count != size->player_dir->total)
		roadblock_msg_b();
	free_map_b(new_map);
}
