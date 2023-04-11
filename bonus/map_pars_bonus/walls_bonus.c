/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:36:31 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 13:37:56 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_walls_b(char *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**rmap;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	rmap = read_map_b(map);
	if (!first_line_b(rmap))
		return (0);
	while (rmap[array_len_b(rmap) - 1][i])
	{
		if (rmap[array_len_b(rmap) - 1][i++] != '1')
			return (free_map_b(rmap), 0);
	}
	i = 0;
	while (rmap[i])
	{
		if ((rmap[i][0] != '1' || rmap[i][ft_strlen(rmap[i]) - 1] != '1'))
			return (free_map_b(rmap), 0);
		i++;
	}
	return (free_map_b(rmap), free(line), 1);
}

int	first_line_b(char **map)
{
	int	i;

	i = 0;
	if (map[0][0] == '\0')
		return (0);
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	rectangular_map_b(char **map)
{
	int		i;
	int		j;
	size_t	width;

	i = 0;
	j = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}
