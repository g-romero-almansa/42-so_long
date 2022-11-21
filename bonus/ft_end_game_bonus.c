/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:51:29 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/07 17:20:25 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_end_game(t_game *game)
{	
	mlx_close_window(game->mlx);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->collec);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->enemy);
	free (game->map);
}
