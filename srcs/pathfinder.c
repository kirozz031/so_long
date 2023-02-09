/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:10:58 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/08 14:20:43 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map1, int y, int i)
{
	int	l;

	l = 0;
	if (map1[y][i] == '1' || map1[y][i] == 'X' || map1[y][i] == 'F')
		return ;
	if (map1[y][i] == 'E')
	{
		map1[y][i] = 'F';
		while (map1[l])
			l++;
		return ;
	}
	else
	{
		map1[y][i] = 'X';
		while (map1[l])
			l++;
		flood_fill(map1, y + 1, i);
		flood_fill(map1, y - 1, i);
		flood_fill(map1, y, i + 1);
		flood_fill(map1, y, i - 1);
	}
}

static int	check_all2(char **str, int size, int len)
{
	int	i;
	int	y;

	y = 0;
	while (y < size)
	{
		i = 0;
		while (i < len)
		{
			if (str[y][i] == 'C' || str[y][i] == 'E')
				return (1);
			i++;
		}
		y++;
	}
	return (0);
}

int	good_path(char **map, t_data data)
{
	char	**map1;
	int		len;
	int		y;
	int		x;

	len = ft_strln(map[0]);
	map1 = NULL;
	map1 = create_map(data.title);
	y = get_pos_y(map1, 'P');
	x = get_pos_x(map1, 'P');
	flood_fill(map1, y, x);
	if (check_all2(map1, map_size(data.title), len) == 0)
	{
		free_maps2(map1, data);
		return (0);
	}
	free_maps2(map1, data);
	return (1);
}
