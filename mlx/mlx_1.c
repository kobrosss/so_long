/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:33:47 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 02:07:29 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	textures(t_init_game *game)
{
	game->textures.coin = mlx_xpm_file_to_image(game->mlx,
	 	"textures/coin.xpm", &(game->lenght), &(game->height));
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
	 	"textures/exit.xpm", &(game->lenght), &(game->height));
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
	 	"textures/floor.xpm", &(game->lenght), &(game->height));
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
	 	"textures/player.xpm", &(game->lenght), &(game->height));
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
	 	"textures/wall.xpm", &(game->lenght), &(game->height));
}

static void puting_textures (t_init_game game, void *textures, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.window, textures, x, y);
}

void	put_textures(t_init_game game)
{
	int	i;
	int	j;

	i = 0;
	while(game.map[i])
	{
		j = 0;
		while(game.map[i][j])
		{
			if (game.map[i][j] == 'C')
				puting_textures(game, game.textures.coin, j * 50, i * 50);
			if (game.map[i][j] == '0')
				puting_textures(game, game.textures.floor, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				puting_textures(game, game.textures.player, j * 50, i * 50);
			if (game.map[i][j] == '1')
				puting_textures(game, game.textures.wall, j * 50, i * 50);
			if (game.map[i][j] == 'E')
				puting_textures(game, game.textures.exit, j * 50, i * 50);
			j++;
		}
		i++;
	}

}

void init_game(t_init_game game)
{
	game.mlx = mlx_init();
	game.lenght = lenth_searcher(game.map);
	game.height = height_searcher(game.map);
	game.window = mlx_new_window(game.mlx, game.lenght * 50, game.height * 50, "so_long");
	coordinates(game.map, game.player_pos, game.exit_pos);
	textures(&game);
	put_textures(game);
	mlx_hook(game.window, 17, 0, free_game, &game);
	mlx_key_hook(game.window, button_events, &game);
	mlx_loop(game.mlx);
}

