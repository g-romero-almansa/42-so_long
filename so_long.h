/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:54:14 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/07 16:16:02 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define WALL	'1'
# define COIN	'C'
# define EXIT	'E'
# define PLAYER	'P'
# define FLOOR	'0'

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*collec;
	mlx_image_t		*exit;
	mlx_image_t		*floor;
	mlx_image_t		*tree;
	mlx_image_t		*player;
	char			**map;
	int				row;
	int				colum;
	int				player_x;
	int				player_y;
	int				collec_count;
	int				player_count;
	int				moves;
}	t_game;

void	ft_error(int num);

void	ft_check_arguments(int argc, char *argv);

void	ft_check_map(char **map, t_game *game);

void	ft_check_collec(t_game *game);

void	ft_init(t_game *game);

void	ft_draw_map(mlx_t *mlx, t_game *game);

void	ft_read_map(char *ber, t_game *game);

void	ft_draw_floor_collec(mlx_t *mlx, t_game *game, int i, int j);

void	ft_draw_floor_player(mlx_t *mlx, t_game *game, int i, int j);

void	hook(mlx_key_data_t keydata, t_game *game);

void	ft_move_w(t_game *game);

void	ft_move_a(t_game *game);

void	ft_move_s(t_game *game);

void	ft_move_d(t_game *game);

void	ft_end_game(t_game *game);

char	*get_next_line(int fd);

#endif
