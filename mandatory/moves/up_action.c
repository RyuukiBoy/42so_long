/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:04:29 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/07 18:15:20 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	go_up(char **map, t_player *items)
{
	int		i;
	int		j;

	i = items->x;
	j = items->y;
	items->direction = P_UP;
	if (map[i - 1][j] == '1')
		return ;
	if (map[i - 1][j] == 'C')
	{
		map[i][j] = '0';
		map[i - 1][j] = 'P';
		items->x--;
		items->count++;
	}
	if (map[i - 1][j] == 'E' && items->count == items->total)
		put_msg(1);
	if (map[i - 1][j] == '0')
	{
		map[i][j] = '0';
		map[i - 1][j] = 'P';
		items->x--;
	}
	ft_printf("Moves : %d\n", items->moves++);
}
