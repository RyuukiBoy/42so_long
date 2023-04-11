/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:11:17 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/11 17:52:04 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*get_player_pos(char **map, t_map size)
{
	int			i;
	int			j;
	t_player	*player;

	i = 0;
	j = 0;
	player = malloc(sizeof(t_player));
	player->moves = 0;
	player->count = 0;
	while (i < size.height)
	{
		while (j < size.width)
		{
			if (map[i][j] == 'P')
			{
				player->x = i;
				player->y = j;
				return (player);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (player);
}
