/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:02:44 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/11 03:44:11 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../keycodes.h"
# include "../mandatory/gnl/gnl.h"
# include "../mandatory/ft_printf/ft_printf.h"
# include "../mandatory/src/so_long.h"

typedef struct s_itemsb		t_itemsb;
typedef struct s_playerb	t_playerb;

typedef struct s_mapb
{
	int			width;
	int			height;
	void		*wall;
	void		*player;
	void		*collectible;
	void		*exit;
	char		**map;
	void		*mlx;
	void		*win;
	void		*up;
	void		*down;
	void		*left;
	void		*right;
	void		*bghost;
	void		*rghost;
	void		*gghost;
	void		*yghost;
	t_itemsb	*items;
	t_playerb	*player_dir;
}				t_mapb;

typedef struct s_playerb
{
	int		x;
	int		y;
	int		count;
	int		total;
	int		moves;
	int		direction;
}				t_playerb;

typedef struct s_itemsb
{
	int			x;
	int			y;
	int			count;
	char		*line;
	char		**map_arr;
	int			collectible;
	int			exit;
	int			player;
	int			direction;
	int			bghost;
	int			rghost;
	int			gghost;
	int			yghost;
	t_playerb	*player_pos;
}				t_itemsb;

typedef struct s_ghost
{
	int		x;
	int		y;
	int		direction;
}				t_ghost;

// bonus
char		*ft_itoa(int n);
int			players_collectibles_exit_enemies(char *map);
int			items_count_b(char *map);
int			ghosts_count(char *map);
int			check_items_b(char **map);
void		check_map_b(char *map);
int			check_line_b(char **map);
char		**read_map_b(char *map);
int			check_extension_b(char *map);
int			check_walls_b(char *map);
int			first_line_b(char **map);
int			rectangular_map_b(char **map);
void		go_up_b(char **map, t_playerb *items);
void		go_down_b(char **map, t_playerb *items);
void		go_left_b(char **map, t_playerb *items);
void		go_right_b(char **map, t_playerb *items);
void		ft_str_replace_b(char *str, char c1, char c2);
int			map_height_b(char *map);
int			map_width_b(char *map);	
int			char_count_b(char **map, char c);
int			array_len_b(char **arr);
void		check_path_b(char **map, t_mapb *size);
int			key_press_b(int keycode, t_mapb *map);
t_playerb	*get_player_pos_b(char **map, t_mapb size);
char		*get_path_b(char c);
void		put_images_b(void *mlx, void *windows, t_mapb size, char **map);
void		init_images_b(t_mapb *map);
void		display_moves_b(t_mapb *sz);
void		free_map_b(char **map);
void		invalid_map_b(void);
void		invalid_extension_b(void);
void		invalid_items_b(void);
void		put_msg_b(int n);
void		roadblock_msg_b(void);
void		animate_ghost(t_mapb *map);

#endif