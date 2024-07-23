/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:02 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/23 18:12:43 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_realloc.c"
#include "ft_memcpy.c"
#include "get_next_line.c"
#include "get_next_line_utils.c"

static void exit_error(const char *message, int fd)
{   
    close(fd);
    perror(message);
    exit(0);
}

char *map_reader(const char *filename)
{
    int fd;
    char *str;
    char *buff;
    char *line;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        exit_error("ERROR(map_reader): failed to open file.", fd);
    str = get_next_line(fd);    
    if (str == NULL)
        exit_error("ERROR(map_reader): map empty.", fd);
    line = get_next_line(fd);
    while (line)
    {
        buff = str;
        str = ft_strjoin(buff, line);
        free(line);
        line = get_next_line(fd);        
    }
    close(fd);    
    return(str);  
}
char **map_spliter (char *map_str)
{
    char **map;
    map = ft_split(map_str, '\n');
    free(map_str);
    return(map);
    
}


