/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:21:19 by bfathi            #+#    #+#             */
/*   Updated: 2025/09/04 01:29:18 by bfathi           ###   ########.fr       */
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

// #include <stdio.h>
// #include <stdlib.h>

// char	**ft_split(char *str, char *charset);

// int	main(void)
// {
// 	char **res;
// 	int i;

// 	char str1[] = "hello world, 42;split, test ";
// 	char *sep1 = ", ";
// 	res = ft_split(str1, sep1);
// 	printf("Case 1: normal\n");
// 	for (i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	printf("\n");

// 	char str2[] = "     ,,,,   ";
// 	char sep2[] = ", ";
// 	res = ft_split(str2, sep2);
// 	printf("Case 2: empty,sep,empty\n");
// 	for (i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	printf("\n");

// 	char str3[] = "";
// 	char sep3[] = ", ";
// 	res = ft_split(str3, sep3);
// 	printf("Case 3:empty string\n");
// 	for (i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	printf("\n");

// 	char str4[] = "nosplitshere";
// 	char sep4[] = ", ";
// 	res = ft_split(str4, sep4);
// 	printf("Case 4:no seps\n");
// 	for (i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	printf("\n");

// 	char str5[] = "a,,b, ,c";
// 	char sep5[] = ", ";
// 	res = ft_split(str5, sep5);
// 	printf("Case 5:double seps\n");
// 	for (i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	printf("\n");

// 	return (0);
// }