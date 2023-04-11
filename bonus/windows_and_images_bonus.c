/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_and_images_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:22:11 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 13:42:02 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_path_b(char c)
{
	if (c == '1')
		return ("./textures/walls.xpm");
	else if (c == 'P')
		return ("./textures/pac_man.xpm");
	else if (c == 'C')
		return ("./textures/pacdot_food.xpm");
	else if (c == 'B')
		return ("./textures/blue_ghost.xpm");
	else if (c == 'R')
		return ("./textures/red_ghost.xpm");
	else if (c == 'G')
		return ("./textures/green_ghost.xpm");
	else if (c == 'Y')
		return ("./textures/yellow_ghost.xpm");
	else if (c == 'E')
		return ("./textures/exit.xpm");
	else
		return (0);
}

void	*get_image(void *mlx, char *path)
{
	void	*img;
	t_mapb	tmp;

	img = mlx_xpm_file_to_image(mlx, path, &tmp.width, &tmp.height);
	return (img);
}

void	put_images_b(void *mlx, void *windows, t_mapb size, char **map)
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
			mimg = get_image(mlx, get_path_b(map[i][j]));
			if (mimg)
				mlx_put_image_to_window(mlx, windows, mimg, j * 32, i * 32);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_images_b(t_mapb *map)
{
	map->wall = get_image(map->mlx, "./textures/walls.xpm");
	map->player = get_image(map->mlx, "./textures/pac_man.xpm");
	map->collectible = get_image(map->mlx, "./textures/pacdot_food.xpm");
	map->exit = get_image(map->mlx, "./textures/exit.xpm");
	map->up = get_image(map->mlx, "./textures/pac_man_up.xpm");
	map->down = get_image(map->mlx, "./textures/pac_man_down.xpm");
	map->left = get_image(map->mlx, "./textures/pac_man_left.xpm");
	map->right = get_image(map->mlx, "./textures/pac_man_right.xpm");
	map->bghost = get_image(map->mlx, "./textures/blue_ghost.xpm");
	map->rghost = get_image(map->mlx, "./textures/red_ghost.xpm");
	map->gghost = get_image(map->mlx, "./textures/green_ghost.xpm");
	map->yghost = get_image(map->mlx, "./textures/yellow_ghost.xpm");
}

void	display_moves_b(t_mapb *sz)
{
	char	*str;

	str = ft_itoa(sz->player_dir->moves);
	mlx_string_put(sz->mlx, sz->win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(sz->mlx, sz->win, 70, 10, 0x00FFFFFF, str);
	free(str);
}
