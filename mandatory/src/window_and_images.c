/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:06:08 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 12:33:08 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_path(char c)
{
	if (c == '1')
		return ("./textures/walls.xpm");
	else if (c == 'P')
		return ("./textures/pac_man.xpm");
	else if (c == 'C')
		return ("./textures/pacdot_food.xpm");
	else if (c == 'E')
		return ("./textures/exit.xpm");
	else
		return (0);
}

void	*get_image(void *mlx, char *path)
{
	void	*img;
	t_map	tmp;

	img = mlx_xpm_file_to_image(mlx, path, &tmp.width, &tmp.height);
	return (img);
}

void	put_images(void *mlx, void *windows, t_map size, char **map)
{
	int		i;
	int		j;
	void	*mimg;

	i = 0;
	j = 0;
	while (i < size.height)
	{
		while (j < size.width)
		{
			mimg = get_image(mlx, get_path(map[i][j]));
			if (mimg)
				mlx_put_image_to_window(mlx, windows, mimg, j * 32, i * 32);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_images(t_map *map)
{
	map->wall = get_image(map->mlx, "./textures/walls.xpm");
	map->player = get_image(map->mlx, "./textures/pac_man.xpm");
	map->collectible = get_image(map->mlx, "./textures/pacdot_food.xpm");
	map->exit = get_image(map->mlx, "./textures/exit.xpm");
	map->up = get_image(map->mlx, "./textures/pac_man_up.xpm");
	map->down = get_image(map->mlx, "./textures/pac_man_down.xpm");
	map->left = get_image(map->mlx, "./textures/pac_man_left.xpm");
	map->right = get_image(map->mlx, "./textures/pac_man_right.xpm");
}
