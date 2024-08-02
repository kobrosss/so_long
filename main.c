/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:44:43 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 21:51:32 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char		*map_str;
	t_init_game	game;

	if (ac == 2)
	{
		game.step_counter = 0;
		map_str = map_reader(av[1]);
		game.map = map_spliter(map_str);
		if (validation(game.map) == -1)
		{
			tablice_cleaner(game.map);
			exit_error("ERROR(validation): the map isn`t valid");
		}
		init_game(game);
		tablice_cleaner(game.map);
	}
	return (0);
}
