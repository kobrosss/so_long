/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:44:43 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/28 20:43:52 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "validation/border_validation.c"
#include "validation/form_validation.c"
#include "validation/map_reader.c"
#include "validation/C_P_E_validation.c"
#include "validation/collecting_validation.c"
#include "validation/validation.c"
#include "libft_utils/ft_bzero.c"
#include "libft_utils/ft_calloc.c"
#include "libft_utils/ft_memcpy.c"
#include "libft_utils/ft_split.c"
#include "libft_utils/ft_strdup.c"
#include "get_next_line/get_next_line.c"
#include "get_next_line/get_next_line_utils.c"
#include "errors_utils/errors.c"
#include "cleaners/tablice_cleaner.c"

int main()
{
	char *map_str;
	char **map;

	map_str = map_reader("mini4.ber");
	map = map_spliter(map_str);
	if(validation(map) == -1)
	{
		tablice_cleaner(map);
		exit_error("ERROR(validation): the map isn`t valid");
	}
	tablice_cleaner(map);
}