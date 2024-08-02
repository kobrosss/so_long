/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:16:53 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 20:39:19 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	border_validation(char **map) {
	size_t	length;
	size_t	height;
	size_t	length_i;
	size_t	height_j;

	length = lenth_searcher(map);
	height = height_searcher(map);
	length_i = 0;
	while (map[length_i]) {
		height_j = 0;
		while (map[length_i][height_j])
		{
			if (length_i == 0 || length_i == height || height_j == 0 || height_j == length)
				if (map[length_i][height_j] != '1')
					return (-1);
			height_j++;
		}
		length_i++;
	}
	return (0);
}

