/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:09:33 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/07 17:43:07 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

char	*check_remainder(char *remainder, char **line)
{
	char	*p;
	
	p = NULL;
	if ((p = ft_strchr(remainder, '\n')))
	{
		*line = ft_substr(remainder, 0, p - remainder);
		p++;
		remainder = ft_memcpy(remainder, p, ft_strlen(p));
	}
	else
	{
		*line = ft_strdup(remainder);	
	}
	return (p);
}

int		get_next_line(int fd, char **line)
{	
	char			buf[1001];
//	char			*tmp;
	int				i;
	static	char	*remainder;
	char			*p;

	if (fd < 0 || !line)
		return (-1);
	p = NULL;
	if (remainder)
		p = check_remainder(remainder, line);
	else
		*line = (char *)malloc(sizeof(char) * 1);
	while (!p && (i = read(fd, buf, 1000)) > 0)
	{
		buf[i] = '\0';
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_substr(*line, 0, ft_strchr(*line, '\n') - *line);
			remainder = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
	return (0);
}

int		main()
{
	int		fd;
	char	*line;

	line = "hello";
	fd = open("file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	
	get_next_line(fd, &line);
	printf("%s\n", line);
}
