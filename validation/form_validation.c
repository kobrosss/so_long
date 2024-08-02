/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:28:40 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 22:20:48 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lenth_searcher(char **map)
{
	size_t	lenth;

	lenth = 0;
	while (map[0][lenth])
		lenth++;
	return (lenth);
}

int	height_searcher(char **map)
{
	size_t	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	form_validator(int lenth, int hight)
{
	if (lenth == hight)
		return (-1);
	if ((lenth < 5 && hight < 3) || (lenth < 3 && hight < 5))
		return (-1);
	return (0);
}
