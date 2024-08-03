/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_P_E_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:34 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/03 02:17:03 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		height;

	height = (int)height_searcher(map);
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	map_copy[height] = NULL;
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	coordinates(char **map_copy, int *player, int *exit)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P' && player)
			{
				player[0] = i;
				player[1] = j;
			}
			if (map_copy[i][j] == 'E' && exit)
			{
				exit[0] = i;
				exit[1] = j;
			}
			j++;
		}
		i++;
	}
}

static void	f_fill(char **map, size_t height, int y, int x)
{
	size_t	length;

	length = lenth_searcher(map);
	if (x < 0 || (x >= (int)length) || y < 0 || (y >= (int)height)
		|| map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	f_fill(map, height, y - 1, x);
	f_fill(map, height, y + 1, x);
	f_fill(map, height, y, x - 1);
	f_fill(map, height, y, x + 1);
}

int	c_p_e_validation(char **map)
{
	char	**map_copy;
	int		player[2];
	size_t	height;

	height = height_searcher(map);
	map_copy = copy_map(map);
	if (!map_copy)
	{
		tablice_cleaner(map_copy);
		return (-1);
	}
	if (p_e_amount(map_copy) == -1)
	{
		tablice_cleaner(map_copy);
		return (-1);
	}
	coordinates(map_copy, player, NULL);
	f_fill(map_copy, height, player[0], player[1]);
	if (!collecting_validation(map_copy))
	{
		tablice_cleaner(map_copy);
		return (-1);
	}
	tablice_cleaner(map_copy);
	return (0);
}
