/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:14:36 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 12:01:07 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put(t_data *data, void *path, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		path, GAMESIZE * x, GAMESIZE * y);
}

void	move_up(t_data *data)
{
	int	a;
	int	b;

	a = data->x_pos;
	b = data->y_pos;
	if (data->map[b - 1][a] == 'E' && check_collect(data->map) == 0)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->map[b - 1][a] != '1' && data->map[b - 1][a] != 'E')
	{
		data->map[b][a] = '0';
		b--;
		data->map[b][a] = 'P';
		data->y_pos = b;
		put_floor(data, data->x_size, data->y_size, data->map);
		put_character(data, data->x_size, data->y_size, data->map);
	}
}

void	move_down(t_data *data)
{
	int	a;
	int	b;

	a = data->x_pos;
	b = data->y_pos;
	if (data->map[b + 1][a] == 'E' && check_collect(data->map) == 0)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->map[b + 1][a] != '1' && data->map[b + 1][a] != 'E')
	{
		data->map[b][a] = '0';
		b++;
		data->map[b][a] = 'P';
		data->y_pos = b;
		put_floor(data, data->x_size, data->y_size, data->map);
		put_character(data, data->x_size, data->y_size, data->map);
	}
}

void	move_left(t_data *data)
{
	int	a;
	int	b;

	a = data->x_pos;
	b = data->y_pos;
	if (data->map[b][a - 1] == 'E' && check_collect(data->map) == 0)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->map[b][a - 1] != '1' && data->map[b][a - 1] != 'E')
	{
		data->map[b][a] = '0';
		a--;
		data->map[b][a] = 'P';
		data->x_pos = a;
		put_floor(data, data->x_size, data->y_size, data->map);
		put_character(data, data->x_size, data->y_size, data->map);
	}
}

void	move_right(t_data *data)
{
	int	a;
	int	b;

	a = data->x_pos;
	b = data->y_pos;
	if (data->map[b][a + 1] == 'E' && check_collect(data->map) == 0)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->map[b][a + 1] != '1' && data->map[b][a + 1] != 'E')
	{
		data->map[b][a] = '0';
		a++;
		data->map[b][a] = 'P';
		data->x_pos = a;
		put_floor(data, data->x_size, data->y_size, data->map);
		put_character(data, data->x_size, data->y_size, data->map);
	}
}
