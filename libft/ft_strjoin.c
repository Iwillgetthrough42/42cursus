/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:43:17 by arastepa          #+#    #+#             */
/*   Updated: 2021/01/28 18:48:20 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen(s1));
	dest[ft_strlen(s1)] = '\0';
	append(dest, s2);
	return (dest);
}
