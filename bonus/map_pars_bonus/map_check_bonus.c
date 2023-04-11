/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:34:44 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 15:55:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_map_b(char *map)
{
	int		fd;
	char	*line;
	char	**map_arr;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	map_arr = read_map_b(map);
	if (rectangular_map_b(map_arr) == 0 || check_items_b(map_arr) == 0)
		invalid_map_b();
	if (!check_extension_b(map))
		invalid_extension_b();
	else if (players_collectibles_exit_enemies(map))
		invalid_items_b();
	else if (check_line_b(map_arr))
		invalid_map_b();
	free(line);
}

int	check_line_b(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'B'
				&& map[i][j] != 'R' && map[i][j] != 'G' && map[i][j] != 'Y')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	free_map_b(map);
	return (0);
}

char	**read_map_b(char *map)
{
	int		fd;
	char	*line;
	int		i;
	char	**map_arr;

	i = 0;
	fd = open(map, O_RDONLY);
	map_arr = (char **)malloc(sizeof(char *) * (map_height_b(map) + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_arr[i] = ft_strdup(line);
		free(line);
		ft_str_replace_b(map_arr[i], '\n', '\0');
		i++;
	}
	free(line);
	close(fd);
	map_arr[i] = 0;
	return (map_arr);
}

int	check_extension_b(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b')
		return (0);
	else if (map[i - 4] != '.')
		return (0);
	return (1);
}
