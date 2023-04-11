/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:06:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/11 20:55:23 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_ghost	*get_ghost(t_mapb *map)
{
	t_ghost	*ghost;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ghost = malloc(sizeof(t_ghost));
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (map->map[i][j] == 'B' || map->map[i][j] == 'R'
			|| map->map[i][j] == 'G' || map->map[i][j] == 'Y')
			{
				ghost->x = j;
				ghost->y = i;
				ghost->direction = 0;
				return (ghost);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ghost);
}

int	get_enemy_count(t_mapb *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (map->map[i][j] == 'B' || map->map[i][j] == 'R'
			|| map->map[i][j] == 'G' || map->map[i][j] == 'Y')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

t_ghost	*create_ghost(int x, int y)
{
	t_ghost	*ghost;

	ghost = malloc(sizeof(t_ghost));
	ghost->x = x;
	ghost->y = y;
	ghost->direction = 0;
	free(ghost);
	return (ghost);
}

t_ghost	**ghost_positions(t_mapb *map)
{
	t_ghost	**ghosts;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	ghosts = malloc(sizeof(t_ghost *) * (get_enemy_count(map) + 1));
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (map->map[i][j] == 'B' || map->map[i][j] == 'R'
			|| map->map[i][j] == 'G' || map->map[i][j] == 'Y')
			ghosts[k++] = create_ghost(j, i);
			j++;
		}
		j = 0;
		i++;
	}
	ghosts[k] = 0;
	return (ghosts);
}

void	animate_ghost(t_mapb *map)
{
	int		i;
	t_ghost	**ghosts;

	i = 0;
	ghosts = ghost_positions(map);
	while (ghosts[i])
	{
		if (map->map[ghosts[i]->y][ghosts[i]->x] == 'B')
			map->map[ghosts[i]->y][ghosts[i]->x] = 'R';
		else if (map->map[ghosts[i]->y][ghosts[i]->x] == 'R')
			map->map[ghosts[i]->y][ghosts[i]->x] = 'B';
		else if (map->map[ghosts[i]->y][ghosts[i]->x] == 'G')
			map->map[ghosts[i]->y][ghosts[i]->x] = 'Y';
		else if (map->map[ghosts[i]->y][ghosts[i]->x] == 'Y')
			map->map[ghosts[i]->y][ghosts[i]->x] = 'G';
		i++;
	}
	free(ghosts);
}
