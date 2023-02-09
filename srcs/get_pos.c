/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:34:51 by arnaud            #+#    #+#             */
/*   Updated: 2023/02/03 19:12:18 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pos_x(char **map, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_pos_y(char **map, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
