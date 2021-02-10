/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:09:33 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/10 15:28:36 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*append(const char *s1, const char *s2)
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

char			*ft_strjoin(char const *s1, char const *s2)
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
	free((char *)s1);
	return (dest);
}

char			*check_remainder(char *remainder, char **line)
{
	char	*p;

	p = NULL;
	if (remainder)
	{
		if ((p = ft_strchr(remainder, '\n')))
		{
			*line = ft_substr(remainder, 0, p - remainder);
			p++;
			ft_memcpy(remainder, p, ft_strlen(remainder));
		}
		else
		{
			*line = ft_strdup(remainder);
			remainder[0] = '\0';
		}
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		*line[0] = 0;
	}
	return (p);
}

int				process_errors(int i, char *p, char **line)
{
	if (i < 0)
		return (-1);
	if ((!i && !p) || (!i && !*line))
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	char			*tmp;
	int				i;
	static	char	*remainder;
	char			*p;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	p = check_remainder(remainder, line);
	if (fd < 0 || !line || !buf)
		return (-1);
	while (!p && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(buf, '\n'))
		{
			tmp = *line;
			*line = ft_substr(*line, 0, ft_strchr(*line, '\n') - *line);
			free(tmp);
			remainder = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
	return (process_errors(i, p, line));
}
