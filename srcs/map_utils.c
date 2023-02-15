/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:05:25 by arnaud            #+#    #+#             */
/*   Updated: 2023/02/13 19:56:54 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size(char *s)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		free (str);
		i++;
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	return (i);
}

char	**create_map(char *s)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_size(s) + 1));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		map[i++] = ft_strdup(str);
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	map[i] = NULL;
	if (str)
		free(str);
	close(fd);
	return (map);
}
