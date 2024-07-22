/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:44 by rkobelie          #+#    #+#             */
/*   Updated: 2024/07/22 21:34:29 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	size;

	if (ptr == 0)
		return (malloc(newsize));
	size = sizeof(ptr);
	if (newsize <= size)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, size);
	free(ptr);
	return (newptr);
}
