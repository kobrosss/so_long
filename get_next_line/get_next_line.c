/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:43:24 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/07/12 17:44:42 by rkobeliev        ###   ########.fr       */
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
/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
