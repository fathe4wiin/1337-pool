/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:43:20 by bfathi            #+#    #+#             */
/*   Updated: 2025/08/14 04:17:38 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printcomb(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar((arr[i] + '0'));
		i++;
	}
	if (arr[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	combogen(int n, int index, int value, int *arr)
{
	if (index == n)
	{
		printcomb(arr, n);
		return ;
	}
	while (value <= 10 - n + index)
	{
		arr[index] = value;
		combogen(n, index + 1, value + 1, arr);
		value++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[9];

	if (n > 0 && n < 10)
		combogen(n, 0, 0, arr);
}
