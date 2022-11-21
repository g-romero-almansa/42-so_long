/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_draw_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:27:48 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/02 11:02:07 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_draw_map(mlx_t *mlx, t_game *game)
{
	int		j;
	int		i;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == WALL)
				mlx_image_to_window(mlx, game->tree, j * 64, i * 64);
		else if (game->map[i][j] == COIN)
			ft_draw_floor_collec(mlx, game, i, j);
		else if (game->map[i][j] == EXIT)
			mlx_image_to_window(mlx, game->exit, j * 64, i * 64);
		else if (game->map[i][j] == PLAYER)
		{
			ft_draw_floor_player(mlx, game, i, j);
			game->player_x = i;
			game->player_y = j;
		}
		else if (game->map[i][j] == FLOOR)
			mlx_image_to_window(mlx, game->floor, j * 64, i * 64);
	}
}

void	ft_draw_floor_collec(mlx_t *mlx, t_game *game, int i, int j)
{
	mlx_image_to_window(mlx, game->floor, j * 64, i * 64);
	mlx_image_to_window(mlx, game->collec, j * 64, i * 64);
}

void	ft_draw_floor_player(mlx_t *mlx, t_game *game, int i, int j)
{
	mlx_image_to_window(mlx, game->floor, j * 64, i * 64);
	mlx_image_to_window(mlx, game->player, j * 64, i * 64);
}

void	ft_read_map(char *ber, t_game *game)
{
	char	*big_str;
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(ber, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	big_str = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		tmp = ft_strjoin(big_str, str);
		big_str = tmp;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close (fd);
	game->map = ft_split(big_str, '\n');
}
