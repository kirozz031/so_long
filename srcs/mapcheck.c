/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:41:18 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/09 12:09:00 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkextension(char *s)
{
	if (s[ft_strlen(s) - 1] == 'r' && s[ft_strlen(s) - 2] == 'e'
		&& s[ft_strlen(s) - 3] == 'b' && s[ft_strlen(s) - 4] == '.')
		return (0);
	else
		return (1);
}

static int	isitarectangle(char **map)
{
	int		size;
	char	*str;
	int		j;
	int		temp;

	temp = strlen(map[0]);
	j = 0;
	size = 0;
	while (map[j])
	{
		str = map[j];
		size = 0;
		while (str[size])
			size++;
		if (temp != size && str[ft_strlen(str) - 1] == '\n')
			return (1);
		temp = size;
		j++;
	}
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
	if (isitarectangle(data.map) == 0
		&& check_only_c_e_p_1_0(data.map) == 0 && isclosed(data.map) == 0
		&& good_path(data.map, data) == 0 && check_p_e(data.map) == 0)
		return (0);
	else
		return (1);
}
