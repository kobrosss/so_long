/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:12:28 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/02 22:16:06 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024

# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_textures
{
	void		*floor;
	void		*wall;
	void		*coin;
	void		*player;
	void		*enemy;
	void		*exit;
}				t_textures;

typedef struct s_init_game
{
	int			lenght;
	int			height;
	int			player_pos[2];
	int			exit_pos[2];
	int			step_counter;
	char		**map;
	void		*window;
	void		*mlx;
	t_textures	textures;
}				t_init_game;

int				height_searcher(char **map);
int				lenth_searcher(char **map);
size_t			ft_strlen(char *s);
int				validation(char **map);
int				c_p_e_validation(char **map);
int				border_validation(char **map);
int				error_minus_one(char *message);
int				free_game(t_init_game *game);
int				form_validator(int lenth, int hight);
int				button_events(int keycode, t_init_game *game);
int				free_game(t_init_game *game);
void			init_game(t_init_game game);
void			put_textures(t_init_game game);
void			moves(t_init_game *game, int x, int y);
bool			collecting_validation(char **map_copy);
void			coordinates(char **map, int *player, int *exit);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			tablice_cleaner(char **map);
void			exit_error(const char *message);
void			exit_error_fd(const char *message, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
char			*get_next_line(int fd);
char			*get_line(char *left_str);
char			*formatnewline(char *rude_str);
char			*readnewline(int fd, char *rude_str);
char			*map_reader(const char *filename);
char			**map_spliter(char *map_str);
char			**ft_split(char const *s, char c);
#endif
