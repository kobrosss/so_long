/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:37:09 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/07/23 21:06:56 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*data;
	size_t	mem;

	mem = nmemb * size;
	if (mem && mem / nmemb != size)
		return (0);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > 2147483647 / size)
		return (NULL);
	data = malloc(nmemb * size);
	if (!data)
		return (NULL);
	ft_bzero(data, nmemb * size);
	return (data);
}
