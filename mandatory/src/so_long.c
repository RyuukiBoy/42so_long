/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:01:57 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 12:32:58 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_items	items;
	t_map	sz;

	if (argc != 2)
		return (1);
	sz.map = read_map(argv[1]);
	sz.height = map_height(argv[1]);
	sz.width = map_width(argv[1]);
	sz.items = &items;
	items.count = 0;
	items.player_pos = get_player_pos(sz.map, sz);
	items.player_pos->direction = 0;
	sz.player_dir = items.player_pos;
	sz.items->player_pos->total = char_count(sz.map, 'C');
	check_map(argv[1]);
	check_path(sz.map, &sz);
	if (rectangular_map(sz.map) == 0 || check_items(sz.map) == 0)
		invalid_map();
	sz.mlx = mlx_init();
	sz.win = mlx_new_window(sz.mlx, sz.width * 32, sz.height * 32, "so_long");
	init_images(&sz);
	put_images(sz.mlx, sz.win, sz, sz.map);
	mlx_hook(sz.win, 2, 0, key_press, &sz);
	mlx_loop(sz.mlx);
	return (0);
}
