/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:30:39 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/10 03:38:13 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	players_collectibles_exit(char *map)
{
	int		fd;
	t_items	items;

	items.x = 0;
	items.player = 0;
	items.collectible = 0;
	items.exit = 0;
	fd = open(map, O_RDONLY);
	items.line = get_next_line(fd);
	items.map_arr = read_map(map);
	if (!items_count(map))
		return (free_map(items.map_arr), free(items.line), 0);
	return (free_map(items.map_arr), free(items.line), 1);
}

int	items_count(char *map)
{
	t_items	items;

	items.x = 0;
	items.y = 0;
	items.player = 0;
	items.collectible = 0;
	items.exit = 0;
	items.map_arr = read_map(map);
	while (items.map_arr[items.x])
	{
		while (items.map_arr[items.x][items.y])
		{
			if (items.map_arr[items.x][items.y] == 'P')
				items.player++;
			else if (items.map_arr[items.x][items.y] == 'C')
				items.collectible++;
			else if (items.map_arr[items.x][items.y] == 'E')
				items.exit++;
			items.y++;
		}
		items.y = 0;
		items.x++;
	}
	free_map(items.map_arr);
	return (items.player != 1 || items.collectible == 0 || items.exit != 1);
}

int	check_items(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
			{
				if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
					roadblock_msg();
				if (map[i - 1][j] == '1' && map[i + 1][j] == '1'
					&& map[i][j - 1] == '1' && map[i][j + 1] == '1')
					roadblock_msg();
			}
			j++;
		}
		i++;
	}
	return (1);
}
