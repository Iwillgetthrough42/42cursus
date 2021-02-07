/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:29:30 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/06 14:29:57 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static		char	*append(const char *s1, const char *s2)
{
	char	*dest;
	char	*src;
	int		i;
	int		len;

	dest = (char *)s1;
	src = (char *)s2;
	i = 0;
	len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
	{
		return (NULL);
	}
	ft_memcpy(dest, s1, lens1);
	dest[lens1] = '\0';
	append(dest, s2);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (str + i);
		}
		i++;
	}
	if (str[i] == c)
	{
		return (str + i);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
	{
		return (NULL);
	}
	i = start;
	if (ft_strlen(s) > start)
	{
		while (i < start + len)
		{
			dest[i - start] = s[i];
			i++;
		}
	}
	dest[i - start] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

