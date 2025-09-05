/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:59:46 by bfathi            #+#    #+#             */
/*   Updated: 2025/08/23 14:22:13 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	revstr(char *str, int i)
{
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) || base[i] == '+'
			|| base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	unsigned int	len;
	char			res[34];
	unsigned int	nb;

	if (base_check(base) == 0)
		return ;
	len = ft_strlen(base);
	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = (unsigned)(-nbr);
	}
	else
		nb = (unsigned)nbr;
	while (nb >= len)
	{
		res[i] = base[(nb % len)];
		i++;
		nb = nb / len;
	}
	res[i] = base[nb % len];
	revstr(res, i);
}
