/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:23:33 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/04 01:29:57 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*res;
	int	i;

	len = max - min;
	if (min >= max)
		return (NULL);
	res = malloc(len * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
