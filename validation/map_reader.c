/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:02 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/03 02:58:43 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*map_reader(const char *filename)
{
	int		fd;
	char	*map_str;
	char	*buff;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error_fd("ERROR(map_reader): failed to open file.", fd);
	map_str = get_next_line(fd);
	if (map_str == NULL)
		exit_error_fd("ERROR(map_reader): map empty.", fd);
	line = get_next_line(fd);
	while (line)
	{
		buff = map_str;
		map_str = ft_strjoin(buff, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_str);
}

char	**map_spliter(char *map_str)
{
	char	**map;

	if (!map_str)
		return (NULL);
	map = ft_split(map_str, '\n');
	if (!map)
		return (NULL);
	free(map_str);
	return (map);
}
