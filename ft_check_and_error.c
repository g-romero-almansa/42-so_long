/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:18:08 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/07 16:19:13 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_error(int num)
{
	if (num == 1)
	{
		ft_printf("Numero de argumentos invalidos\n");
		exit (EXIT_FAILURE);
	}
	else if (num == 2)
	{
		ft_printf("El mapa no es uno valido\n");
		exit (EXIT_FAILURE);
	}
}

void	ft_check_arguments(int argc, char *argv)
{
	if (argc != 2)
		ft_error(1);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4))
		ft_error(2);
}

void	ft_check_map(char **map, t_game *game)
{
	int		i;
	int		j;

	while (map[game->row])
	{
		while (map[game->row][game->colum])
			game->colum++;
		game->row++;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if ((i == 0 || i == (game->row - 1) || j == 0
					|| j == (game->colum - 1)) && map[i][j] != WALL)
				ft_error(2);
		else if (map[i][j] != WALL && map[i][j] != COIN && map[i][j] != EXIT
					&& map[i][j] != PLAYER && map[i][j] != FLOOR)
			ft_error(2);
		if (j != game->colum)
			ft_error(2);
	}
}

void	ft_check_collec(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->collec_count++;
			else if (game->map[i][j] == 'P')
				game->player_count++;
		}
	}
	if (game->player_count != 1)
		ft_error(2);
}
