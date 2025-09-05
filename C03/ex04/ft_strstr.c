/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:46:26 by bfathi            #+#    #+#             */
/*   Updated: 2025/08/21 15:53:52 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	to_find_len;

	to_find_len = 0;
	while (to_find[to_find_len])
	{
		to_find_len++;
	}
	if (to_find_len == 0)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, to_find, to_find_len) == 0)
			return (str);
		str++;
	}
	return (0);
}
