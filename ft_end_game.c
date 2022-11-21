/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:51:29 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/02 10:55:48 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_end_game(t_game *game)
{	
	mlx_close_window(game->mlx);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->collec);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->player);
	free (game->map);
}
