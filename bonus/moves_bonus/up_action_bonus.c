/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:57:42 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 17:25:24 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	norm_up(char **map, t_playerb *items)
{
	map[items->x][items->y] = '0';
	map[items->x - 1][items->y] = 'P';
	items->x--;
	items->count++;
}

void	go_up_b(char **map, t_playerb *items)
{
	int		i;
	int		j;

	i = items->x;
	j = items->y;
	items->direction = P_UP;
	if (map[i - 1][j] == '1')
		return ;
	if (map[i - 1][j] == 'C')
		norm_up(map, items);
	if (map[i - 1][j] == 'E' && items->count == items->total)
		put_msg_b(1);
	if (map[i - 1][j] == 'B' || map[i - 1][j] == 'R' ||
		map[i - 1][j] == 'G' || map[i - 1][j] == 'Y')
		put_msg_b(2);
	if (map[i - 1][j] == '0')
	{
		map[i][j] = '0';
		map[i - 1][j] = 'P';
		items->x--;
	}
	ft_printf(KCYN"Moves : %d\n", items->moves++);
}
