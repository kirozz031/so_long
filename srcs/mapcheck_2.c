/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:11:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/02/13 14:45:16 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_only_c_e_p_1_0(char **map)
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
			if (str[j] != 'C' && str[j] != 'P' && str[j] != 'E'
				&& str[j] != '1' && str[j] != '0'
				&& str[j] != '\n' && str[j] != '\0' )
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_p_e(char **map)
{
	int		i;
	int		j;
	int		e;
	int		p;
	char	*str;

	i = 0;
	p = 0;
	e = 0;
	while (map[++i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
		{
			if (str[j] == 'P')
				p++;
			if (str[j] == 'E')
				e++;
		}
	}
	if (p == 0 || p >= 2 || e >= 2 || e == 0)
		return (1);
	return (0);
}

int	check_c(char **map, char co)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	i = 0;
	j = 0;
	c = 0;
	while (map[++i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
		{
			if (str[j] == co)
				c++;
		}
	}
	if (c == 0)
		return (1);
	return (0);
}

int	check_collect(char **map)
{
	int		i;
	int		j;
	int		collectibles;
	char	*str;

	i = 0;
	collectibles = 0;
	while (map[++i])
	{
		str = map[i];
		j = 0;
		while (str[j++])
			if (str[j] == 'C')
				collectibles++;
	}
	return (collectibles);
}

int	checkextension(char *s)
{
	if (s[ft_strlen(s) - 1] == 'r' && s[ft_strlen(s) - 2] == 'e'
		&& s[ft_strlen(s) - 3] == 'b' && s[ft_strlen(s) - 4] == '.')
		return (0);
	else
		return (1);
}
