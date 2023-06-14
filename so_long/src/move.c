/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:10:18 by joberle           #+#    #+#             */
/*   Updated: 2022/07/13 15:11:50 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	finish(t_game *game)
{
	game->player.move++;
	ft_printf("\nNombres total de deplacements : %d\n", game->player.move);
	exit_game(game);
}

void	move_up(t_game *game)
{
	find_player(game);
	if (game->map.tab[game->player.y][game->player.x] == 'P')
	{
		if (game->map.tab[game->player.y - 1][game->player.x] != '1')
		{
			if (game->map.tab[game->player.y - 1][game->player.x] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y - 1][game->player.x] == 'E'
					&& game->player.item == 0)
				finish(game);
			if (game->map.tab[game->player.y - 1][game->player.x] == 'E'
					&& game->player.item != 0)
				return ;
			if (game->map.tab[game->player.y - 1][game->player.x] == 'D')
			{
				ft_printf(RED"\nMORT\n"WHT);
				exit_game(0);
			}
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y - 1][game->player.x] = 'P';
			game->player.move++;
		}
	}
	ft_printf(GRN"\nNombres de deplacements : %d\n"WHT, game->player.move);
	return ;
}

void	move_down(t_game *game)
{
	find_player(game);
	if (game->map.tab[game->player.y][game->player.x] == 'P')
	{
		if (game->map.tab[game->player.y + 1][game->player.x] != '1')
		{
			if (game->map.tab[game->player.y + 1][game->player.x] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y + 1][game->player.x] == 'E'
				&& game->player.item == 0)
				finish(game);
			if (game->map.tab[game->player.y + 1][game->player.x] == 'E'
					&& game->player.item != 0)
				return ;
			if (game->map.tab[game->player.y + 1][game->player.x] == 'D')
			{
				ft_printf(RED"\nMORT\n"WHT);
				exit_game(game);
			}
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y + 1][game->player.x] = 'P';
			game->player.move++;
		}
	}
	ft_printf(GRN"\nNombres de deplacements : %d\n"WHT, game->player.move);
	return ;
}

void	move_left(t_game *game)
{
	find_player(game);
	if (game->map.tab[game->player.y][game->player.x] == 'P')
	{
		if (game->map.tab[game->player.y][game->player.x - 1] != '1')
		{
			if (game->map.tab[game->player.y][game->player.x - 1] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y][game->player.x - 1] == 'E'
					&& game->player.item == 0)
				finish(game);
			if (game->map.tab[game->player.y][game->player.x - 1] == 'E'
					&& game->player.item != 0)
				return ;
			if (game->map.tab[game->player.y][game->player.x - 1] == 'D')
			{
				ft_printf(RED"\nMORT\n"WHT);
				exit_game(game);
			}
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y][game->player.x - 1] = 'P';
			game->player.move++;
		}
	}
	ft_printf(GRN"\nNombres de deplacements : %d\n"WHT, game->player.move);
	return ;
}

void	move_right(t_game *game)
{
	find_player(game);
	if (game->map.tab[game->player.y][game->player.x] == 'P')
	{
		if (game->map.tab[game->player.y][game->player.x + 1] != '1')
		{
			if (game->map.tab[game->player.y][game->player.x + 1] == 'C')
				game->player.item--;
			if (game->map.tab[game->player.y][game->player.x + 1] == 'E'
					&& game->player.item == 0)
				finish(game);
			if (game->map.tab[game->player.y][game->player.x + 1] == 'E'
					&& game->player.item != 0)
				return ;
			if (game->map.tab[game->player.y][game->player.x + 1] == 'D')
			{
				ft_printf(RED"\nMORT\n"WHT);
				exit_game(game);
			}
			game->map.tab[game->player.y][game->player.x] = '0';
			game->map.tab[game->player.y][game->player.x + 1] = 'P';
			game->player.move++;
		}
	}
	ft_printf(GRN"\nNombres de deplacements : %d\n"WHT, game->player.move);
	return ;
}
