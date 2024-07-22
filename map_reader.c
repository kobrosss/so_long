/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:02 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/22 23:54:08 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_realloc.c"
#include "ft_memcpy.c"

static void exit_error(const char *message, int fd)
{   
    close(fd);
    perror(message);
    exit(EXIT_FAILURE);
}

static void exit_free_error(const char *message, int fd, t_map *map)
{   
    perror(message);
    close(fd);
    if (map != NULL) {
        if (map->buffer != NULL) {
            free(map->buffer);
        }
    }
    exit(EXIT_FAILURE);
}

char *map_reader(t_map *map, const char *filename)
{
    int fd;
    char *map_row;
    ssize_t buffer_size;

    buffer_size = BUFFER_SIZE;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        exit_error("ERROR(map_reader): failed to open file.", fd);
    map->buffer = malloc(BUFFER_SIZE);
    if (map->buffer == NULL)
        exit_error("ERROR(map_reader): allocation of memory.", fd);
    while ((map->bytes = read(fd, map->buffer + map->size, buffer_size - map->size)) > 0)
    {
        map->size += map->bytes;
        if (map->size == buffer_size)
        {
            buffer_size *= 2;
            map->new_buffer = ft_realloc(map->buffer, buffer_size + 1);
            if (map->new_buffer == NULL)
                exit_free_error("ERROR(map_reader): realocation of memory", fd, map);
            map->buffer = map->new_buffer;            
        }
    }
    if (map->bytes == -1)
        exit_free_error("ERROR(map_reader): bad reading", fd, map);
    close(fd);
    printf("amount of symbols: %zu\n", map->size);
    map->buffer[map->size + 1] = '\0';
    map_row = map->buffer;
    return (map_row);
}

int main()
{
    t_map map;
    map.buffer = NULL;
    map.new_buffer = NULL;
    map.next = NULL;
    map.size = 0;

    const char *filename = "mini4.ber";
    char *file_content = map_reader(&map, filename);
    free(file_content);
    return 0;
}
