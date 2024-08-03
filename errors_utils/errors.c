/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:20:17 by rkobelie          #+#    #+#             */
/*   Updated: 2024/08/03 02:20:48 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error_fd(const char *message, int fd)
{
	close(fd);
	perror(message);
	exit(0);
}

void	exit_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
