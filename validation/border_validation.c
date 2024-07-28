/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:16:53 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 03:03:30 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	border_validation (char **map)
{
	size_t	lenth;
	size_t	height;
	size_t	lenth_i;
	size_t	height_j;

	lenth = lenth_searcher(map) - 1;
	height = height_searcher(map) - 1;
	lenth_i = -1 ;

	while(++lenth_i, map[lenth_i])
	{
		height_j = 0;
		while(++height_j, map[lenth_i][height_j])
		{
			if(lenth_i == 0 || lenth_i == height
				|| height_j == 0 || height_j == lenth)
				if(map[lenth_i][height_j] != '1')
					return(error_minus_one("ERROR (border_validtion)"));

		}
	}
	return(0);
}

