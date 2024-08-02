/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:56:16 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 22:18:07 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validation(char **map)
{
	size_t	lenth;
	size_t	height;

	lenth = lenth_searcher(map);
	height = height_searcher(map);
	if (form_validator(lenth, height) == -1)
		return (-1);
	else if (border_validation(map) == -1)
		return (-1);
	else if (c_p_e_validation(map) == -1)
		return (-1);
	else
		return (0);
}
