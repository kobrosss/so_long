/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablice_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:19:01 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/26 17:16:16 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void tablice_cleaner(char **map, size_t height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}