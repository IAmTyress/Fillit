/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrosaura <rrosaura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:40:29 by rrosaura          #+#    #+#             */
/*   Updated: 2019/04/11 18:34:18 by rrosaura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_separator(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

static int		count_words(char *str, const char *charset)
{
	int	i;
	int	count;

	i = 0;
	while (str[i] && is_separator(str[i], charset))
		i++;
	if (str[i] != !is_separator(str[i], charset))
		count = 1;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && is_separator(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

static int		word_size(char *str, char const *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && !is_separator(str[i], charset))
	{
		++size;
		++i;
	}
	return (size);
}

static char		**ft_strsplitpool(char *str, const char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!(tab = (char **)malloc(sizeof(char *) *
					(count_words(str, charset) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!is_separator(str[i], charset))
		{
			if (index == -1 || is_separator(str[i - 1], charset))
			{
				if (!(tab[++index] = (char *)malloc(sizeof(char) *
								(word_size(str + i, charset) + 1))))
					return (NULL);
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	tab[++index] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*charset;

	if (!s || !c)
		return (NULL);
	if (!(charset = ft_strnew(2)))
		return (NULL);
	charset[0] = c;
	return (ft_strsplitpool((char *)s, charset));
}
