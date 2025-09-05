/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:14:24 by bfathi            #+#    #+#             */
/*   Updated: 2025/08/20 02:37:33 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char c)
{
	if (!(((c >= 'a') && (c <= 'z'))
			|| ((c >= 'A') && (c <= 'Z'))))
		return (0);
	else
		return (1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z') && ft_char_is_alpha(str[i]))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
