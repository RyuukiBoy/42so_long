/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:50:56 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/07 18:15:41 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	go_left(char **map, t_player *items)
{
	int		i;
	int		j;

	i = items->x;
	j = items->y;
	items->direction = P_LEFT;
	if (map[i][j - 1] == '1')
		return ;
	if (map[i][j - 1] == 'C')
	{
		map[i][j] = '0';
		map[i][j - 1] = 'P';
		items->y--;
		items->count++;
	}
	if (map[i][j - 1] == 'E' && items->count == items->total)
		put_msg(1);
	if (map[i][j - 1] == '0')
	{
		map[i][j] = '0';
		map[i][j - 1] = 'P';
		items->y--;
	}
	ft_printf("Moves : %d\n", items->moves++);
}
