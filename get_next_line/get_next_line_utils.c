/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:51:57 by rkobeliev         #+#    #+#             */
/*   Updated: 2024/04/15 18:58:56 by rkobeliev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *rude_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rude_str)
	{
		rude_str = (char *)malloc(1 * sizeof(char));
		rude_str[0] = '\0';
	}
	if (!rude_str || !buffer)
		return (NULL);
	str = malloc(sizeof(char) *((ft_strlen(rude_str) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rude_str)
		while (rude_str[++i] != '\0')
			str[i] = rude_str[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(rude_str) + ft_strlen(buffer)] = '\0';
	free(rude_str);
	return (str);
}

char	*get_line(char *rude_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rude_str[i])
		return (NULL);
	while (rude_str[i] && rude_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rude_str[i] && rude_str[i] != '\n')
	{
		str[i] = rude_str[i];
		i++;
	}
	if (rude_str[i] == '\n')
	{
		str[i] = rude_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*formatnewline(char *rude_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rude_str[i] && rude_str[i] != '\n')
		i++;
	if (!rude_str[i])
	{
		free(rude_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rude_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rude_str[i])
		str[j++] = rude_str[i++];
	str[j] = '\0';
	free(rude_str);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
