/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:43:27 by joberle           #+#    #+#             */
/*   Updated: 2022/07/14 16:06:30 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define ECHAP 53
# define PLAYER "img/butter.xpm"
# define FLOOR "img/floor_texture.xpm"
# define EXIT  "img/exit_texture.xpm"
# define ITEM  "img/collect.xpm"
# define WALL "img/wall_texture.xpm"
# define DIE "img/cartman.xpm"
# define IMG_SIZE 20;
# define GRN "\e[0;32m"
# define WHT "\e[0;37m"
# define RED "\e[0;31m"

typedef struct s_img
{
	void	*img;
	int		taille;
	int		x;
	int		y;

}	t_img;

typedef struct s_player
{
	t_img	img;
	int		item;
	int		move;
	int		exit;
	int		x;
	int		y;
}	t_player;

typedef struct s_map
{
	t_img	floor;
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	die;
	char	**tab;
	int		item;
	int		x;
	int		y;
	int		fd;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*path;
	int			x;
	int			y;
	t_map		map;
	t_player	player;
}	t_game;

char	**init_tab(int fd);
int		exit_game(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		find_item(char **s, t_game *game);
int		find_player(t_game *game);
void	error_exit(t_game *game);
int		find_exit(char **s);
int		key_action(int key, t_game *game);
void	init_game(t_game *game, char *av);
void	load_img(t_game *game);
void	print_floor(t_game *game);
void	print_player(t_game *game);
int		print_img(t_game *game);
void	error_game(t_game *game);
int		is_ber(char *str);
void	is_ok(char **str, t_game *game);
#endif
