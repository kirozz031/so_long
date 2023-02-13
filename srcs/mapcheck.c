/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:41:18 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/13 13:52:54 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(char *str)
{
	if (str)
		free(str);
}

static int	isitarectangle(char *s)
{
	char	*str;
	int		i;
	int		fd;
	int		len;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	len = ft_strln(str);
	while (str)
	{
		if (len != ft_strln(str))
		{
			free(str);
			return (1);
		}
		ft_free(str);
		i++;
		str = get_next_line(fd);
	}
	ft_free(str);
	close(fd);
	return (0);
}

static int	isclosed(char **map)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	str = map[j];
	while (str[i++])
		if (str[i] != '1' && str[i] != '\n' && str[i] != '\0')
			return (1);
	i = 0;
	while (map[j])
	{	
		str = map[j];
		i = 0;
		if ((str[0] != '1') || (str[strlen(str) - 2] != '1'))
			return (1);
		j++;
	}
	if (isclosed_2(map[j - 1]) == 1)
		return (1);
	return (0);
}

int	isclosed_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n' && str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_all(t_data data)
{
	if (isitarectangle(data.title) == 0 && check_c(data.map, 'C') == 0
		&& check_only_c_e_p_1_0(data.map) == 0 && isclosed(data.map) == 0
		&& check_p_e(data.map) == 0 && good_path(data.map, data) == 0)
		return (0);
	else
		return (1);
}
