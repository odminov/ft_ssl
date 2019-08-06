/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:10:09 by ahonchar          #+#    #+#             */
/*   Updated: 2018/08/29 17:49:26 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *str, char c)
{
	int		i;
	int		words;
	int		in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			in_word = 1;
			i++;
		}
		if (in_word)
			words++;
		in_word = 0;
		if (str[i])
			i++;
	}
	return (words);
}

static int	count_simb(char **str, char c)
{
	int		i;
	int		spaces;

	i = 0;
	while (**str && **str == c)
	{
		i++;
		(*str)++;
	}
	spaces = i;
	while (**str && **str != c)
	{
		i++;
		(*str)++;
	}
	return (i - spaces);
}

static char	**copy_to_arr(const char *str, char **arr, char c)
{
	int		i;
	int		wd;

	wd = 0;
	while (*str)
	{
		i = 0;
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			while (*str && *str != c)
				arr[wd][i++] = *str++;
			arr[wd][i] = '\0';
			wd++;
		}
		if (*str)
			str++;
	}
	return (arr);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		wd;
	char	**res;
	char	*copy;

	if (!str || c == '\0')
		return (NULL);
	wd = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * wd + 1);
	i = 0;
	copy = (char *)str;
	while (i < wd)
		res[i++] = (char *)malloc(count_simb(&copy, c) + 1);
	res[i] = NULL;
	return (copy_to_arr(str, res, c));
}
