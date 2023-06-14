/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:32:23 by joberle           #+#    #+#             */
/*   Updated: 2022/07/14 16:18:57 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map.tab);
	exit(0);
}

void	is_ok(char **str, t_game *game)
{
	int	i;
	int	a;
	int	nb;

	a = 0;
	i = 0;
	nb = 1;
	while (str[a + 1])
	{
		while (str[a][i] != '\n')
		{
			if (str[a][i] == '1' || str[a][i] == '0')
				nb--;
			else if (str[a][i] == 'E' || str[a][i] == 'P')
				nb--;
			else if (str[a][i] == 'C' || str[a][i] == 'D')
				nb--;
			if (nb == 1)
				error_exit(game);
			i++;
			nb = 1;
		}
		a++;
		i = 0;
	}
}
