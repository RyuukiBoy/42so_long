/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:32:54 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/06 20:31:48 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	check_map(char *map)
{
	int		fd;
	char	*line;
	char	**map_arr;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	map_arr = read_map(map);
	if (!check_extension(map))
		invalid_extension();
	else if (players_collectibles_exit(map))
		invalid_items();
	else if (check_line(map_arr))
		invalid_map();
	free(line);
}

int	check_line(char **map)
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
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	free_map(map);
	return (0);
}

char	**read_map(char *map)
{
	int		fd;
	char	*line;
	int		i;
	char	**map_arr;

	i = 0;
	fd = open(map, O_RDONLY);
	map_arr = (char **)malloc(sizeof(char *) * (map_height(map) + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_arr[i] = ft_strdup(line);
		free(line);
		ft_str_replace(map_arr[i], '\n', '\0');
		i++;
	}
	free(line);
	close(fd);
	map_arr[i] = 0;
	return (map_arr);
}

int	check_extension(char *map)
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
