/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:36:31 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/02 18:29:48 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*malloc_null(char *res)
{
	res = malloc(1);
	res[0] = '\0';
	return (res);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		seplen;
	int		strslen;

	seplen = ft_strlen(sep);
	i = 0;
	strslen = 0;
	while (i < size)
		strslen += ft_strlen(strs[i++]);
	res = malloc(strslen + (seplen * (size - 1)) + 1);
	if (size == 0)
		return (malloc_null(res));
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// char *ft_strjoin(int size, char **strs, char *sep);

// int main(void)
// {
//     char *tab1[] = {"Hello", "world", "42"};
//     char *tab2[] = {"One"};
//     char *tab3[] = {};

//     char *res;

//     // Test 1: Normal join
//     res = ft_strjoin(3, tab1, ", ");
//     if (res)
//     {
//         printf("Test 1: %s\n", res);
//         free(res);
//     }

//     // Test 2: Only one string
//     res = ft_strjoin(1, tab2, " - ");
//     if (res)
//     {
//         printf("Test 2: %s\n", res);
//         free(res);
//     }

//     // Test 3: Empty array
//     res = ft_strjoin(0, tab3, ", ");
//     if (res)
//     {
//         printf("Test 3: '%s'\n", res);
//         free(res);
//     }

//     // Test 4: Different separator
//     res = ft_strjoin(3, tab1, " *** ");
//     if (res)
//     {
//         printf("Test 4: %s\n", res);
//         free(res);
//     }

//     return (0);
// }
