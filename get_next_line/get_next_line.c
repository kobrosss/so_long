/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:43:24 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/07/23 18:43:16 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*readnewline(int fd, char *rude_str)
{
	int		readbytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(rude_str, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbytes] = '\0';
		rude_str = ft_strjoin(rude_str, buffer);
	}
	free(buffer);
	return (rude_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rude_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rude_str = readnewline(fd, rude_str);
	if (!rude_str)
		return (NULL);
	line = get_line(rude_str);
	rude_str = formatnewline(rude_str);
	return (line);
}
