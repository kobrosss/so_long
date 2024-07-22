/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:28 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/22 23:36:50 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define BUFFER_SIZE 1024

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>


typedef struct s_list
{
	ssize_t bytes;
    ssize_t  size;
    char    **map;
    char    *buffer;
    char    *new_buffer;
	struct s_list	*next;
}				t_map;


char   *map_reader(t_map *map, const char *filename);
char	**ft_split(char const *s, char c);
void	*ft_realloc(void *ptr, size_t newsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif