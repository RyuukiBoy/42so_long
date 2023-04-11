/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:35:38 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 15:53:10 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	players_collectibles_exit_enemies(char *map)
{
	int			fd;
	t_itemsb	items;

	items.x = 0;
	items.player = 0;
	items.collectible = 0;
	items.exit = 0;
	items.bghost = 0;
	items.rghost = 0;
	items.yghost = 0;
	items.gghost = 0;
	fd = open(map, O_RDONLY);
	items.line = get_next_line(fd);
	items.map_arr = read_map_b(map);
	if (!items_count_b(map))
		return (free_map_b(items.map_arr), free(items.line), 0);
	if (!ghosts_count(map))
		return (free_map_b(items.map_arr), free(items.line), 0);
	return (free_map_b(items.map_arr), free(items.line), 1);
}

int	items_count_b(char *map)
{
	t_itemsb	items;

	items.x = 0;
	items.y = 0;
	items.player = 0;
	items.collectible = 0;
	items.exit = 0;
	items.map_arr = read_map_b(map);
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
	free_map_b(items.map_arr);
	return (items.player != 1 || items.collectible == 0 || items.exit != 1);
}

int	ghosts_count(char *map)
{
	t_itemsb	items;

	items.x = 0;
	items.y = 0;
	items.map_arr = read_map_b(map);
	while (items.map_arr[items.x])
	{
		while (items.map_arr[items.x][items.y])
		{
			if (items.map_arr[items.x][items.y] == 'B')
				items.bghost++;
			else if (items.map_arr[items.x][items.y] == 'R')
				items.rghost++;
			else if (items.map_arr[items.x][items.y] == 'Y')
				items.yghost++;
			else if (items.map_arr[items.x][items.y] == 'G')
				items.gghost++;
			items.y++;
		}
		items.y = 0;
		items.x++;
	}
	free_map_b(items.map_arr);
	return (items.bghost == 0 || items.rghost == 0
		|| items.yghost == 0 || items.gghost == 0);
}

int	check_items_b(char **map)
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
					roadblock_msg_b();
				if (map[i - 1][j] == '1' && map[i + 1][j] == '1'
					&& map[i][j - 1] == '1' && map[i][j + 1] == '1')
					roadblock_msg_b();
			}
			j++;
		}
		i++;
	}
	return (1);
}
