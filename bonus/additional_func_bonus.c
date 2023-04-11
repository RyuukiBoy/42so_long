/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:41:30 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 15:58:44 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_str_replace_b(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
}

int	map_height_b(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
			break ;
		i++;
	}
	free(line);
	return (i);
}

int	map_width_b(char *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line[i])
		i++;
	if (line[i - 1] == '\n')
		i--;
	free(line);
	return (i);
}

int	array_len_b(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr && arr[i])
		i++;
	return (i);
}

int	char_count_b(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
