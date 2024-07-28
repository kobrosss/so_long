/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablice_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:19:01 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 20:00:09 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void tablice_cleaner(char **map)
{
	size_t i;

	if (map)
	{
		i = 0;
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}