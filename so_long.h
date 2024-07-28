/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:28 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 20:00:16 by rkobelie         ###   ########.fr       */
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


int validation(char **map);
char	*ft_strdup(const char *s);
bool collecting_validation(char **map_copy);
void coordinates(char **map, int *player, int *exit);
int c_p_e_validation(char **map);
int	border_validation (char **map);
void tablice_cleaner(char **map);
void exit_error(const char *message);
void exit_error_fd(const char *message, int fd);
int error_minus_one(char *message);
int   form_validator(size_t lenth, size_t hight);
size_t  height_searcher(char **map);
size_t  lenth_searcher(char **map);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*get_line(char *left_str);
char	*formatnewline(char *rude_str);
char	*readnewline(int fd, char *rude_str);
char   *map_reader(const char *filename);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
