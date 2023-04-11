/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:00:03 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 17:25:19 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	norm_right(char **map, t_playerb *items)
{
	map[items->x][items->y] = '0';
	map[items->x][items->y + 1] = 'P';
	items->y++;
	items->count++;
}

void	go_right_b(char **map, t_playerb *items)
{
	int		i;
	int		j;

	i = items->x;
	j = items->y;
	items->direction = P_RIGHT;
	if (map[i][j + 1] == '1')
		return ;
	if (map[i][j + 1] == 'C')
		norm_right(map, items);
	if (map[i][j + 1] == 'E' && items->count == items->total)
		put_msg_b(1);
	if (map[i][j + 1] == 'B' || map[i][j + 1] == 'R' ||
		map[i][j + 1] == 'G' || map[i][j + 1] == 'Y')
		put_msg_b(2);
	if (map[i][j + 1] == '0')
	{
		map[i][j] = '0';
		map[i][j + 1] = 'P';
		items->y++;
	}
	ft_printf(KCYN"Moves : %d\n", items->moves++);
}
