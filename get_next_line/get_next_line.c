/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:09:33 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/09 13:20:54 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 

char	*check_remainder(char *remainder, char **line)
{
	char	*p;
	//char 	*temp;

	p = NULL;
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
	return (p);
}

int		get_next_line(int fd, char **line)
{	
	char			*buf;
	char			*tmp;
	int				i;
	static	char	*remainder;
	char			*p;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(-1);
	if (fd < 0 || !line)
		return (-1);
	p = NULL;
	if (remainder)
		p = check_remainder(remainder, line);
	else
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (-1);
	while (!p && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (ft_strchr(*line, '\n'))
		{
			tmp = *line;
			*line = ft_substr(*line, 0, ft_strchr(*line, '\n') - *line);
			free(tmp);
			remainder = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
	if (i < 0)
		return (-1);
	if ((!i && !p) || (!i && !*line))
		return (0);
	return (1);
}