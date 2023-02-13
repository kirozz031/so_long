/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:27:55 by lusezett          #+#    #+#             */
/*   Updated: 2023/02/13 15:02:27 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (2, &s[i], 1);
		i++;
	}
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-214748364", 10);
		nb = 8;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb > 0)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
