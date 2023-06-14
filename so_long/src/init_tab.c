/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:32:08 by joberle           #+#    #+#             */
/*   Updated: 2022/07/14 15:39:09 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**init_tab(int fd)
{
	int		a;
	char	**str;

	str = malloc(sizeof(char *) * (100));
	a = -1;
	while (1)
	{
		str[++a] = get_next_line(fd);
		if (str[a] == NULL)
			break ;
	}
	return (str);
}

void	init_value(t_game *game)
{
	game->map.coin.x = 0;
	game->map.coin.y = 0;
	game->map.exit.x = 0;
	game->map.exit.y = 0;
	game->map.wall.x = 0;
	game->map.wall.y = 0;
	game->map.floor.x = 0;
	game->map.floor.y = 0;
	game->player.move = 0;
}

void	init_game(t_game *game, char *av)
{
	game->path = av;
	if (is_ber(game->path))
	{
		ft_printf("Error\n");
		exit(0);
	}
	game->map.fd = open(game->path, O_RDONLY);
	if (game->map.fd == -1)
	{
		ft_printf("Error\n");
		exit(0);
	}
	game->map.tab = init_tab(game->map.fd);
	error_game(game);
	init_value(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.x * 80,
			game->map.y * 80, "so_long");
}
