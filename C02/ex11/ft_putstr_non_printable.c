/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:12:01 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/02 18:37:15 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
	{
		return (0);
	}
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar(hexa[(unsigned char)str[i] / 16]);
			ft_putchar(hexa[(unsigned char)str[i] % 16]);
		}
		i++;
	}
}
