/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:28:40 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/27 14:49:19 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t  lenth_searcher(char **map)
{
    size_t lenth;

    lenth = 0;
    while(map[0][lenth])
        lenth++;
    return(lenth);
}

size_t  height_searcher(char **map)
{
    size_t height;

    height = 0;
    while(map[height] != NULL)
        height++;
    return(height);
}

int form_validator(size_t lenth, size_t hight)
{
    if (lenth == hight)
        exit_error("ERROR(form_validation): the map is not rectangular");
    if ((lenth < 5 && hight < 3) || (lenth < 3 && hight < 5))
        exit_error("ERROR(form_validation): the map can't contain sprites");
    return(1);
}