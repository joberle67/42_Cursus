/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:50:30 by joberle           #+#    #+#             */
/*   Updated: 2022/07/14 14:14:06 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	load_img(t_game *game)
{
	game->x = 80;
	game->y = 80;
	game->player.img.img = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->x, &game->y);
	game->map.floor.img = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->x, &game->y);
	game->map.exit.img = mlx_xpm_file_to_image(game->mlx, EXIT,
			&game->x, &game->y);
	game->map.coin.img = mlx_xpm_file_to_image(game->mlx, ITEM,
			&game->x, &game->y);
	game->map.wall.img = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->x, &game->y);
	game->map.die.img = mlx_xpm_file_to_image(game->mlx, DIE,
			&game->x, &game->y);
}

void	print_player(t_game *game)
{
	find_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img.img,
		game->player.x * 80, game->player.y * 80);
}

void	print_wall(t_game *game)
{
	int	i;
	int	a;

	a = -1;
	i = 0;
	while (game->map.tab[++a])
	{
		while (game->map.tab[a][i])
		{
			if (game->map.tab[a][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.wall.img, i * 80, a * 80);
			else if (game->map.tab[a][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.exit.img, i * 80, a * 80);
			else if (game->map.tab[a][i] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.coin.img, i * 80, a * 80);
			else if (game->map.tab[a][i] == 'D')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.die.img, i * 80, a * 80);
			i++;
		}
		i = 0;
	}
}

int	print_img(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	print_wall(game);
	print_player(game);
	mlx_string_put(game->mlx, game->win, 10, 10,
		255255255, ft2_itoa(game->player.move));
	return (0);
}
