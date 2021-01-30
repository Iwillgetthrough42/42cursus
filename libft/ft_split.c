/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:38:02 by arastepa          #+#    #+#             */
/*   Updated: 2021/01/30 12:37:59 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static	char	*malloc_tmp(char *str, char c)
{
	char	*st;
	int		i;
	char	*tmp;

	st = str;
	while (*str && *str != c)
		str++;
	if (!(tmp = (char *)malloc(sizeof(char) * (str - st + 1))))
		return (NULL);
	i = 0;
	while (i < str - st)
	{
		tmp[i] = st[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			**ft_split(char const *s, char c)
{
	char	*str;
	char	**arr;
	int		j;
	char	*tmp;

	j = 0;
	str = (char *)s;
	if (!(arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1))))
		return (NULL);
	while (*str != '\0')
	{
		while (*str && *str == c)
			str++;
		if (*str == '\0')
			break ;
		if (*str != c)
		{
			tmp = malloc_tmp(str, c);
			arr[j++] = ft_strdup(tmp);
			while (*str && *str != c)
				str++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
