/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:38:27 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 17:23:15 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_playerb	*get_player_pos_b(char **map, t_mapb size)
{
	int			i;
	int			j;
	t_playerb	*player;

	i = 0;
	j = 0;
	player = malloc(sizeof(t_playerb));
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
