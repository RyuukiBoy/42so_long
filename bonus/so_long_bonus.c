/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:02:33 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/11 18:46:57 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game(t_mapb size)
{
	size.mlx = mlx_init();
	size.win = mlx_new_window(size.mlx, size.width * 32, size.height * 32,
			"so_long");
	init_images_b(&size);
	put_images_b(size.mlx, size.win, size, size.map);
	display_moves_b(&size);
	mlx_hook(size.win, 2, 0, key_press_b, &size);
	mlx_loop(size.mlx);
}

int	main(int argc, char **argv)
{
	t_itemsb	items;
	t_mapb		size;

	if (argc != 2)
		return (1);
	size.map = read_map_b(argv[1]);
	size.height = map_height_b(argv[1]);
	size.width = map_width_b(argv[1]);
	size.items = &items;
	items.count = 0;
	items.player_pos = get_player_pos_b(size.map, size);
	items.player_pos->direction = 0;
	size.player_dir = items.player_pos;
	size.items->player_pos->total = char_count_b(size.map, 'C');
	check_map_b(argv[1]);
	check_path_b(size.map, &size);
	init_game(size);
	return (0);
}
