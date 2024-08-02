/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:05:59 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 02:07:24 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	button_events(int keycode,t_init_game *game)
{
	if (keycode == 119)
		moves(game, -1, 0);
	if (keycode == 115)
		moves(game, 1, 0);
	if (keycode == 97)
		moves(game, 0, -1);
	if (keycode == 100)
		moves(game, 0, 1);
	if (keycode == 65307)
		free_game(game);
	return (0);
}

void	moves(t_init_game *game, int x_add, int y_add)
{
	int	x;
	int	y;

	x = game->player_pos[0] + x_add;
	y = game->player_pos[1] + y_add;
	if (game->map[x][y] == '1')
		return ;
	if (game->map[x][y] == 'e')
		free_game(game);
	if (game->map)
		game->map[x][y] = 'P';
	if ((x == game->exit_pos[0]) && (y == game->exit_pos[1]))
		if(collecting_validation(game->map))
			free_game(game);
	if (game->player_pos[0] == game->exit_pos[0] && game->player_pos[1] == game->exit_pos[1])
		game->map[game->player_pos[0]][game->player_pos[1]] = 'E';
	else
		game->map[game->player_pos[0]][game->player_pos[1]] = '0';
	game->player_pos[0] = x;
	game->player_pos[1]= y;
	put_textures(*game);
}

int	free_game(t_init_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.exit);
	mlx_destroy_image(game->mlx, game->textures.floor);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	tablice_cleaner(game->map);
	exit(0);
}