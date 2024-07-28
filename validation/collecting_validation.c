/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:46:52 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 03:52:03 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool collecting_validation(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_copy[i] != NULL)
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}