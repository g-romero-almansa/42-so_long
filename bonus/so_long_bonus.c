/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:37:17 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/21 12:17:38 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_init2(t_game *game)
{
	game->texture = mlx_load_png("images/tree.png");
	game->tree = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/collec.png");
	game->collec = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/player.png");
	game->player = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/enemy.png");
	game->enemy = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("images/exit2.png");
	game->exit2 = mlx_texture_to_image(game->mlx, game->texture);
	mlx_delete_texture(game->texture);
}

void	ft_init(t_game *game)
{
	game->row = 0;
	game->colum = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->collec_count = 0;
	game->player_count = 0;
}

void	hook(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move_w(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move_a(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move_s(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move_d(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check_arguments(argc, argv[1]);
	game = malloc (sizeof(t_game));
	ft_read_map(argv[1], game);
	ft_init(game);
	ft_check_map(game->map, game);
	game->mlx = mlx_init(game->colum * 64, game->row * 64, "so_long", true);
	ft_init2(game);
	ft_check_collec(game);
	ft_draw_map(game->mlx, game);
	mlx_put_string(game->mlx, "0", 1 * 16, 1 * 16);
	mlx_key_hook(game->mlx, (mlx_keyfunc)hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free (game);
	return (0);
}
