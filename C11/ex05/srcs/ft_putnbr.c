/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:00:23 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/03 17:05:41 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned)(-nb);
	}
	else
		nbr = (unsigned)(nb);
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
}
