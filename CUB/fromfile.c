/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:10:30 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 15:02:15 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	init(t_mapdata *data)
{
	data->resx = 0;
	data->resy = 0;
	data->north = 0;
	data->south = 0;
	data->west = 0;
	data->east = 0;
	data->sprite = 0;
	data->floor = 0;
	data->ceilling = 0;
	data->map = 0;
	data->mapy = 0;
}

void	skipspaces(char **line)
{
	while (**line == '\t' || **line == '\n' || **line == '\v' ||
			**line == '\f' || **line == '\r' || **line == ' ')
		(*line)++;
}

void	checkline(char *line, t_mapdata *data, int *i)
{
	while (*line != '\0')
	{
		if (*line == 'R' && *(line + 1) == ' ')
			ft_res(&line, data, i);
		else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
			ft_dir(&line, &data->north, i);
		else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
			ft_dir(&line, &data->south, i);
		else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
			ft_dir(&line, &data->west, i);
		else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
			ft_dir(&line, &data->east, i);
		else if (*line == 'S' && *(line + 1) == ' ')
			ft_dir(&line, &data->sprite, i);
		else if (*line == 'F' && *(line + 1) == ' ')
			ft_color(&line, &data->floor, i, data);
		else if (*line == 'C' && *(line + 1) == ' ')
			ft_color(&line, &data->ceilling, i, data);
		else if (*i > 7)
			ft_map(&line, data);
		else
			ft_error1(data);
	}
}

int		checkmap(t_mapdata *data)
{
	int i;
	int j;
	int lstcol;

	i = 0;
	j = 0;
	while (i < data->mapy)
	{
		lstcol = ft_strlen(data->map[i]) - 1;
		j = 0;
		while (ft_isspace(data->map[i][j]))
			j++;
		while (ft_isspace(data->map[i][lstcol]))
			lstcol--;
		while (j < lstcol)
		{
			if (!ft_isspace(data->map[i][j]) && (!ft_bool1(data, i, j)))
				if (data->map[i][j] != '1')
					ft_error2(data);
			j++;
		}
		i++;
	}
	return (1);
}

int		readfile(t_mapdata *data)
{
	int		fd;
	char	*line;
	int		t;
	int		cnt;
	int		i;

	i = 0;
	cnt = ft_count(data);
	t = 1;
	init(data);
	if (!(data->map = (char **)malloc(sizeof(char *) * (cnt))))
		return (0);
	if ((fd = open(data->file, O_RDONLY)) == -1)
		exit(0);
	while (t)
	{
		t = get_next_line(fd, &line);
		if (i < 8)
			skipspaces(&line);
		checkline(line, data, &i);
	}
	checkmap(data);
	checkmapins(data);
	return (1);
}
