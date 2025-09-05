/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:44:25 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/02 18:29:46 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);

int		base_index(char c, char *base);

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
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (res_calc(i, base, str, len) * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*res;

	if (!base_check(base_to) || !base_check(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	res = ft_putnbr_base(nb, base_to);
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// char *ft_convert_base(char *nbr, char *base_from, char *base_to);

// int main(void)
// {
//     char *res;

//     // 1. Simple decimal to binary
//     res = ft_convert_base("42", "0123456789", "01");
//     printf("Case 1 (42 dec -> bin): %s\n", res);
//     free(res);

//     // 2. Decimal zero
//     res = ft_convert_base("0", "0123456789", "01");
//     printf("Case 2 (0 dec -> bin): %s\n", res);
//     free(res);

//     // 3. Negative decimal
//     res = ft_convert_base("-42", "0123456789", "0123456789ABCDEF");
//     printf("Case 3 (-42 dec -> hex): %s\n", res);
//     free(res);

//     // 4. Base with invalid chars (duplicate)
//     res = ft_convert_base("42", "012233456789", "01");
//     printf("Case 4 (invalid base_from duplicate): %s\n", res);

//     // 5. Base too short
//     res = ft_convert_base("42", "0", "01");
//     printf("Case 5 (invalid base_from length < 2): %s\n", res);

//     // 6. Invalid character in nbr
//     res = ft_convert_base("4Z", "0123456789", "0123456789");
//     printf("Case 6 (invalid char in number): %s\n", res);

//     // 7. Convert between same base (identity)
//     res = ft_convert_base("12345", "0123456789", "0123456789");
//     printf("Case 7 (same base): %s\n", res);
//     free(res);

//     // 8. Leading spaces and plus sign
//     res = ft_convert_base("   +42", "0123456789", "01");
//     printf("Case 8 (leading spaces and +): %s\n", res);
//     free(res);

//     // 9. Multiple signs
//     res = ft_convert_base(" --+-42", "0123456789", "0123456789");
//     printf("Case 9 (multiple signs): %s\n", res);
//     free(res);

//     // 10. Very large number
//     res = ft_convert_base("2147483647", "0123456789", "01");
//     printf("Case 10 (INT_MAX dec -> bin): %s\n", res);
//     free(res);

//     return 0;
// }