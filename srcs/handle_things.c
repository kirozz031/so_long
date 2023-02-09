/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:04:27 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/09 12:01:26 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	char	*i;

	i = data;
	i++;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == 113)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (keysym == XK_w)
		move_up(data);
	else if (keysym == XK_s)
		move_down(data);
	else if (keysym == XK_a)
		move_left(data);
	else if (keysym == XK_d)
		move_right(data);
	return (0);
}
