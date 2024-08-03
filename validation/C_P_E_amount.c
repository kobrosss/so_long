/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_E_amount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:02:14 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/03 18:06:21 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	p_e_amount(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (-1);
	return (0);
}

static int	c_amount (char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		return (-1);
	return (0);
}

int	c_p_e_amount (char **map)
{
	if (c_amount (map) == -1 ||
		p_e_amount(map) == -1)
		return (-1);
	return (0);
}

