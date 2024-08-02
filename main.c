/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:44:43 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/01 23:59:37 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_init_game game;
	char *map_str;

	map_str = map_reader("map.ber");
	game.map = map_spliter(map_str);
	if(validation(game.map) == -1)
	{
		tablice_cleaner(game.map);
		exit_error("ERROR(validation): the map isn`t valid");
	}
	init_game(game);
	tablice_cleaner(game.map);
	return (0);

}