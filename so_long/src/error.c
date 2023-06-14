/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joberle <joberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:32:21 by joberle           #+#    #+#             */
/*   Updated: 2022/07/14 16:10:48 by joberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	error_exit(t_game *game)
{
	(void)game;
	ft_printf("Error\n");
	exit(0);
}

int	error_map(char **str, t_game *game)
{
	int	a;
	int	i;
	int	nb;

	a = 0;
	i = 0;
	nb = 0;
	while (str[a][nb] != '\n' && str[a][nb])
		nb++;
	while (str[a])
	{
		while (str[a][i] != '\n' && str[a][i])
			i++;
		if (i != nb)
			return (0);
		game->map.y = a + 1;
		game->map.x = i;
		a++;
		i = 0;
	}
	if (game->map.y == nb)
		return (0);
	return (1);
}

int	if_not_close(char **str)
{
	int	a;
	int	i;

	a = 1;
	i = 0;
	while (str[0][i + 1])
	{
		if (str[0][i] != '1')
			return (0);
		i++;
	}
	while (str[a])
	{
		if (str[a][0] != '1' || str[a][i - 1] != '1')
			return (0);
		a++;
	}
	i = 0;
	while (str[a - 1][i + 1])
	{
		if (str[a - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_ber(char *str)
{
	int		i;
	int		a;
	char	*tab;

	i = ft_strlen(str);
	a = 0;
	tab = ".ber";
	while (str[i] != '.' && i > 0)
		i--;
	while (str[i])
	{
		if (str[i] != tab[a])
			return (1);
		i++;
		a++;
	}
	if (i == 0)
		return (1);
	return (0);
}

void	error_game(t_game *game)
{
	if (error_map(game->map.tab, game) == 0)
		error_exit(game);
	if (!find_player(game) || !find_item(game->map.tab, game))
		error_exit(game);
	if (!find_exit(game->map.tab) || !if_not_close(game->map.tab))
		error_exit(game);
	is_ok(game->map.tab, game);
}
