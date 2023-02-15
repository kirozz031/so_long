/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:03:58 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/13 19:45:47 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(char **map, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->y_size)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	free_maps2(char **map, t_data data)
{
	int		y;
	int		i;

	i = 0;
	y = map_size(data.title);
	while (i < y)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	exit_file_error(int n, t_data data)
{
	if (n == 0)
		write(2, "Error\nProbleme Malloc Map", 26);
	else if (n == 1)
		write(2, "Error\nMauvaise Map !", 20);
	else if (n == 2)
		write(2, "Error\nMauvaise Extension !", 27);
	free_maps2(data.map, data);
	exit (1);
}

int	clear_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->chara);
	mlx_destroy_image(data->mlx_ptr, data->collectible);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free_maps(data->map, data);
	exit(1);
}
