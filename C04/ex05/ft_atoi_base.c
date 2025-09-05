/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 01:59:56 by bfathi            #+#    #+#             */
/*   Updated: 2025/08/23 14:22:28 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_index(char c, char *base);

int	res_calc(int i, char *base, char *str, int len)
{
	int	value;
	int	res;

	res = 0;
	while (str[i])
	{
		value = base_index(str[i], base);
		if (value == -1)
			break ;
		res = res * len + value;
		i++;
	}
	return (res);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
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
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	len;

	neg = 1;
	i = 0;
	len = base_check(base);
	if (len == 0)
	{
		return (0);
	}
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
	{
		i++;
	}
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (res_calc(i, base, str, len) * neg);
}
