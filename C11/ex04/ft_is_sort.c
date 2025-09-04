/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:40:57 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/03 19:25:16 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	asc = 1;
	desc = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			desc = 0;
		i++;
	}
	if (asc || desc)
		return (1);
	else
		return (0);
}
