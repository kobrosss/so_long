/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:28:40 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/23 21:35:19 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void exit_error(const char *message)
{
    perror(message);
    exit(0);
}

size_t  lenth_searcher(char **map)
{
    size_t lenth;

    lenth = 0;
    while(map[0][lenth])
        lenth++;
    return(lenth);
}

size_t  width_searcher(char **map)
{
    size_t width;

    width = 0;
    while(map[width] != NULL)
        width++;
    return(width);
}

int form_validator(size_t lenth, size_t width)
{
    if (lenth == width)
        exit_error("ERROR(form_validation): the map is not rectangular");
    if ((lenth < 5 && width < 3) || (lenth < 3 && width < 5))
        exit_error("ERROR(form_validation): the map can't contain sprites");
    return(1);
}