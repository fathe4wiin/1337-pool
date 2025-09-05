/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 01:38:32 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/03 01:39:15 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_issep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], sep))
			i++;
		if (str[i] && !ft_issep(str[i], sep))
		{
			words++;
			while (str[i] && !ft_issep(str[i], sep))
				i++;
		}
	}
	return (words);
}

void	skip_sep(char *str, char *charset, int *i, int *wordlen)
{
	*wordlen = 0;
	while (str[*i] && ft_issep(str[*i], charset))
		(*i)++;
	while (str[*i] && !ft_issep(str[*i], charset))
	{
		(*wordlen)++;
		(*i)++;
	}
	*i -= *wordlen;
}

char	*extract_words(char *str, int *i, char *charset, int wordlen)
{
	char	*res;
	int		k;

	k = 0;
	res = malloc(wordlen + 1);
	if (!res)
		return (NULL);
	while (str[*i] && !ft_issep(str[*i], charset))
	{
		res[k] = str[*i];
		k++;
		(*i)++;
	}
	res[k] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		wordlen;
	int		j;

	res = malloc((word_count(str, charset) + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		skip_sep(str, charset, &i, &wordlen);
		if (wordlen > 0)
		{
			res[j] = extract_words(str, &i, charset, wordlen);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
