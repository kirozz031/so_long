/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:05:34 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/09 14:35:50 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "../minilibx/minilibx-linux/mlx.h"

# define GAMESIZE 64

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;

	void	*floor;
	void	*wall;
	void	*exit;
	void	*chara;
	void	*collectible;

	int		img_width;
	int		img_height;
	char	img_path;

	char	**map;
	char	*title;
	int		x_size;
	int		y_size;

	int		x_pos;
	int		y_pos;

	int		place;
	int		place2;
	int		size;
}			t_data;

int		check_p_e(char **map);
int		ft_strlen(char *str);
int		map_size(char *s);
int		check_only_c_e_p_1_0(char **map);
int		checkextension(char *s);
int		map_size(char *s);
int		check_all(t_data data);
int		isclosed_2(char *s);
int		get_pos_x(char **map, char c);
int		get_pos_y(char **map, char c);
int		check_collect(char **map);
int		check_P_E(char **map);
int		good_path(char **map, t_data data);
int		ft_strln(char *str);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		destroy(t_data *data);

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	**create_map(char *s);
char	*ft_strdup(char *s);

void	mlx_put_content(t_data *data, int x, int y, char **map);
void	mlx_put(t_data *data, void *path, int x, int y);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	put_walls(t_data *data, int x, int y, char **map);
void	put_floor(t_data *data, int x, int y, char **map);
void	put_character(t_data *data, int x, int y, char **map);
void	put_exit(t_data *data, int x, int y, char **map);
void	put_collectible(t_data *data, int x, int y, char **map);
void	put_walls2(t_data *data, int x, int y, char **map);
void	free_maps2(char **map, t_data data);
void	ft_putstr(char *s);
void	*ft_put_img(t_data *data, char *path);

#endif
