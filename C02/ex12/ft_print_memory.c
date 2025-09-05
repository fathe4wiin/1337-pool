/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:47:29 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/02 18:40:30 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	print_hexa(unsigned char *str, unsigned int size)
{
	unsigned int	i;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		write(1, &hex[str[i] / 16], 1);
		write(1, &hex[str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		write(1, " ", 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_adress(unsigned long int addr)
{
	int		i;
	char	*hex;
	char	hex_adress[16];

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		hex_adress[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	write(1, hex_adress, 16);
	write(1, ": ", 2);
}

void	ft_print_memory__(void *addr, unsigned int size)
{
	unsigned long	dec_addr;

	dec_addr = (unsigned long)addr;
	print_adress(dec_addr);
	print_hexa(addr, size);
	print_str(addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)addr;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < 16 && (j + i) < size)
			i++;
		ft_print_memory__(str + j, i);
		j += i;
	}
	return (addr);
}

// int	main(void)
// {
// 	char str0[] = "";
// 	char str1[] = "A";
// 	char str2[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
// 	char str3[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
// 	char str4[20] = "edge case testing!!!";
// 	char str5[64];
// 	for (int i = 0; i < 64; i++)
// 		str5[i] = (char)(i + 32);
// 	char str6[] = "tiny";

// 	ft_print_memory(str0, 0);
// 	ft_print_memory(str1, sizeof(str1));
// 	ft_print_memory(str2, sizeof(str2));
// 	ft_print_memory(str3, sizeof(str3));
// 	ft_print_memory(str4, sizeof(str4));
// 	ft_print_memory(str5, sizeof(str5));
// 	ft_print_memory(str6, 100);

// 	return (0);
// }