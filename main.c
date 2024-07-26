/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:44:43 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/26 20:49:08 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "validation/border_validation.c"
#include "validation/form_validation.c"
#include "validation/map_reader.c"
#include "libft_utils/ft_bzero.c"
#include "libft_utils/ft_calloc.c"
#include "libft_utils/ft_memcpy.c"
#include "libft_utils/ft_split.c"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"
#include "errors_utils/errors.c"
#include "cleaners/tablice_cleaner.c"

int main()
{
	char *map_str = map_reader("mini4.ber");
	char **map = map_spliter(map_str);
	size_t lenth = lenth_searcher(map);
	size_t height = height_searcher(map);
	form_validator(lenth, height);
	border_validation(map);
	tablice_cleaner(map, height);


}