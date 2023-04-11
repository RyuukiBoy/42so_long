/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:35:31 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/11 18:47:28 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_ghosts(t_mapb *m, int i, int j)
{
	if (m->map[i][j] == 'B')
		mlx_put_image_to_window(m->mlx, m->win, m->bghost, j * 32, i * 32);
	else if (m->map[i][j] == 'R')
		mlx_put_image_to_window(m->mlx, m->win, m->rghost, j * 32, i * 32);
	else if (m->map[i][j] == 'G')
		mlx_put_image_to_window(m->mlx, m->win, m->gghost, j * 32, i * 32);
	else if (m->map[i][j] == 'Y')
		mlx_put_image_to_window(m->mlx, m->win, m->yghost, j * 32, i * 32);
}

void	render_tile(t_mapb *m, int i, int j)
{
	if (m->map[i][j] == 'P')
	{
		if (m->player_dir->direction == P_UP)
			mlx_put_image_to_window(m->mlx, m->win, m->up, j * 32, i * 32);
		else if (m->player_dir->direction == P_DOWN)
			mlx_put_image_to_window(m->mlx, m->win, m->down, j * 32, i * 32);
		else if (m->player_dir->direction == P_LEFT)
			mlx_put_image_to_window(m->mlx, m->win, m->left, j * 32, i * 32);
		else if (m->player_dir->direction == P_RIGHT)
			mlx_put_image_to_window(m->mlx, m->win, m->right, j * 32, i * 32);
		else
			mlx_put_image_to_window(m->mlx, m->win, m->player, j * 32, i * 32);
	}
	else if (m->map[i][j] == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->wall, j * 32, i * 32);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(m->mlx, m->win, m->collectible, j * 32, i * 32);
	else if (m->map[i][j] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->exit, j * 32, i * 32);
	render_ghosts(m, i, j);
}

void	render_map_b(t_mapb *map)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(map->mlx, map->win);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			render_tile(map, i, j);
			j++;
		}
		i++;
	}
}

int	key_press_b(int keycode, t_mapb *map)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		go_up_b(map->map, map->items->player_pos);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		go_down_b(map->map, map->items->player_pos);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		go_left_b(map->map, map->items->player_pos);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		go_right_b(map->map, map->items->player_pos);
	else if (keycode == ESC_KEY)
		put_msg_b(0);
	render_map_b(map);
	animate_ghost(map);
	display_moves_b(map);
	return (0);
}
