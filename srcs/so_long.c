/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:28:33 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/13 15:22:27 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*init_content(t_data *data)
{
	data->moves = 0;
	data->x_size = (ft_strlen(data->map[1]) - 1);
	data->y_size = map_size(data->title);
	data->x_pos = get_pos_x(data->map, 'P');
	data->y_pos = get_pos_y(data->map, 'P');
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (NULL);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->x_size * GAMESIZE,
			data->y_size * GAMESIZE, "so_long");
	if (data->mlx_win == NULL)
		return (NULL);
	data->wall = ft_put_img(data, "xpm/sapin1.xpm");
	data->floor = ft_put_img(data, "xpm/snow.xpm");
	data->chara = ft_put_img(data, "xpm/chara.xpm");
	data->exit = ft_put_img(data, "xpm/exit.xpm");
	data->collectible = ft_put_img(data, "xpm/cadeau.xpm");
	return (data);
}

static int	init(t_data *data)
{
	data = init_content(data);
	if (!data)
		return (0);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->x_size, data->y_size);
	if (!data->img_ptr)
		return (0);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->mlx_win, 17, 0, &destroy, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	put_walls(data, data->x_size, data->y_size, data->map);
	put_floor(data, data->x_size, data->y_size, data->map);
	put_character(data, data->x_size, data->y_size, data->map);
	put_exit(data, data->x_size, data->y_size, data->map);
	put_collectible(data, data->x_size, data->y_size, data->map);
	mlx_loop(data->mlx_ptr);
	destroy(data);
	return (0);
}

void	*ft_put_img(t_data *data, char *path)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	return (mlx_xpm_file_to_image(data->mlx_ptr, path, &a, &b));
}

int	main(int ac, char **av)
{
	t_data	data;

	data.title = av[1];
	if (ac == 2 && checkextension(data.title) == 0)
	{
		data.map = create_map(data.title);
		if (!data.map)
			exit_file_error(0, data);
		if (check_all(data) == 0)
			init(&data);
		else
			exit_file_error(1, data);
	}
	else
	{
		write(1, "Error\nMauvais Argument !", 25);
		exit(1);
	}
	return (0);
}
