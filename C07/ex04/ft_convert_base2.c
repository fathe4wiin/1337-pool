/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:47:37 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/02 18:29:47 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);

int		base_index(char c, char *base);

char	*str_rev(char *reversed_nb, int j, char *res, int i)
{
	while (--i >= 0)
		res[j++] = reversed_nb[i];
	res[j] = '\0';
	return (res);
}

int	base__check(char *base)
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
	return (i);
}

char	*str_zero(char *res, char *base)
{
	res[0] = base[0];
	res[1] = '\0';
	return (res);
}

char	*revstr(int nb, char *base, int len, int neg)
{
	int		i;
	char	reversed_nb[34];
	char	*res;
	int		j;

	i = 0;
	if (nb == 0)
	{
		res = malloc(2);
		return (str_zero(res, base));
	}
	while (nb > 0)
	{
		reversed_nb[i++] = base[nb % len];
		nb /= len;
	}
	res = (char *)malloc(i);
	j = 0;
	if (neg == -1)
	{
		res[0] = '-';
		j++;
	}
	return (str_rev(reversed_nb, j, res, i));
}

char	*ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	long int		nb;
	int				neg;

	neg = 1;
	len = base__check(base);
	if (len == 0)
		return (0);
	nb = nbr;
	if (nb < 0)
	{
		neg = -1;
		nb = -nb;
	}
	return (revstr(nb, base, len, neg));
}
