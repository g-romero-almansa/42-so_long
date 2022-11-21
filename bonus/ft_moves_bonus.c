/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:42:23 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/07 17:31:32 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_move_w(t_game *game)
{
	if (game->map[game->player_x - 1][game->player_y] != '1'
		&& (game->map[game->player_x - 1][game->player_y] != 'E'
		|| game->collec_count == 0))
	{
		game->map[game->player_x][game->player_y] = '0';
		if (game->map[game->player_x - 1][game->player_y] == 'C')
			game->collec_count--;
		if ((game->map[game->player_x - 1][game->player_y] == 'E'
			&& game->collec_count == 0)
			|| game->map[game->player_x - 1][game->player_y] == 'D')
			ft_end_game(game);
		else
		{
			game->map[game->player_x - 1][game->player_y] = 'P';
			ft_draw_map(game->mlx, game);
			game->moves++;
			mlx_put_string(game->mlx, ft_itoa(game->moves), 1 * 16, 1 * 16);
		}
	}
}

void	ft_move_a(t_game *game)
{
	if (game->map[game->player_x][game->player_y - 1] != '1'
		&& (game->map[game->player_x][game->player_y - 1] != 'E'
		|| game->collec_count == 0))
	{
		game->map[game->player_x][game->player_y] = '0';
		if (game->map[game->player_x][game->player_y - 1] == 'C')
			game->collec_count--;
		if ((game->map[game->player_x][game->player_y - 1] == 'E'
			&& game->collec_count == 0)
			|| game->map[game->player_x][game->player_y - 1] == 'D')
			ft_end_game(game);
		else
		{
			game->map[game->player_x][game->player_y - 1] = 'P';
			ft_draw_map(game->mlx, game);
			game->moves++;
			mlx_put_string(game->mlx, ft_itoa(game->moves), 1 * 16, 1 * 16);
		}
	}
}

void	ft_move_s(t_game *game)
{
	if (game->map[game->player_x + 1][game->player_y] != '1'
		&& (game->map[game->player_x + 1][game->player_y] != 'E'
			|| game->collec_count == 0))
	{
		game->map[game->player_x][game->player_y] = '0';
		if (game->map[game->player_x + 1][game->player_y] == 'C')
			game->collec_count--;
		if ((game->map[game->player_x + 1][game->player_y] == 'E'
			&& game->collec_count == 0)
			|| game->map[game->player_x + 1][game->player_y] == 'D')
			ft_end_game(game);
		else
		{
			game->map[game->player_x + 1][game->player_y] = 'P';
			ft_draw_map(game->mlx, game);
			game->moves++;
			mlx_put_string(game->mlx, ft_itoa(game->moves), 1 * 16, 1 * 16);
		}
	}
}

void	ft_move_d(t_game *game)
{
	if (game->map[game->player_x][game->player_y + 1] != '1'
		&& (game->map[game->player_x][game->player_y + 1] != 'E'
		|| game->collec_count == 0))
	{
		game->map[game->player_x][game->player_y] = '0';
		if (game->map[game->player_x][game->player_y + 1] == 'C')
			game->collec_count--;
		if ((game->map[game->player_x][game->player_y + 1] == 'E'
			&& game->collec_count == 0)
			|| game->map[game->player_x][game->player_y + 1] == 'D')
			ft_end_game(game);
		else
		{
			game->map[game->player_x][game->player_y + 1] = 'P';
			ft_draw_map(game->mlx, game);
			game->moves++;
			mlx_put_string(game->mlx, ft_itoa(game->moves), 1 * 16, 1 * 16);
		}
	}
}
