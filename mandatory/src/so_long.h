/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:02:08 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 12:30:42 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../../keycodes.h"
# include "../gnl/gnl.h"
# include "../ft_printf/ft_printf.h"
# include "../../bonus/so_long_bonus.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define P_UP 1
# define P_DOWN 2
# define P_LEFT 3
# define P_RIGHT 4
# define ROWS 1
# define COLS 1

typedef struct s_items	t_items;
typedef struct s_player	t_player;

typedef struct s_map
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
	t_items		*items;
	t_player	*player_dir;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		count;
	int		total;
	int		moves;
	int		direction;
}				t_player;

typedef struct s_items
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
	t_player	*player_pos;
}				t_items;

// utlis
int			array_len(char **arr);
void		ft_str_replace(char *str, char c1, char c2);
int			map_height(char *map);
int			map_width(char *map);
int			char_count(char **map, char c);
int			check_items(char **map);
void		free_map(char **map);

// map_pars
int			check_walls(char *map);
int			first_line(char **map);
int			players_collectibles_exit(char *map);
void		check_map(char *map);
char		**read_map(char *map);
int			check_extension(char *map);
int			items_count(char *map);
int			check_line(char **map);
int			rectangular_map(char **map);
char		**copy_map(char **map, t_map *size);
void		check_path(char **map, t_map *size);

// srcs
void		render_map(t_map *size);
int			key_press(int keycode, t_map *map);
void		go_up(char **map, t_player *items);
void		go_down(char **map, t_player *items);
void		go_left(char **map, t_player *items);
void		go_right(char **map, t_player *items);
t_player	*get_player_pos(char **map, t_map size);
void		init_images(t_map *size);
void		put_images(void *mlx, void *windows, t_map size, char **map);

// errors
void		invalid_map(void);
void		invalid_extension(void);
void		invalid_items(void);
void		put_msg(int n);
void		roadblock_msg(void);

#endif