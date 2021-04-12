/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:17:35 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 15:20:13 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_count(t_mapdata *data)
{
	int			fd;
	char		*line;
	int			t;
	int			i;
	int			l;

	i = 0;
	t = 1;
	if ((fd = open(data->file, O_RDONLY)) == -1)
		exit(0);
	while (t)
	{
		t = get_next_line(fd, &line);
		if (l < 8)
			skipspaces(&line);
		if (l > 7)
			i++;
		l++;
	}
	return (i);
}

void	ft_map(char **line, t_mapdata *data)
{
	data->map[data->mapy] = ft_strdup(*line);
	*line += ft_strlen(*line);
	(data->mapy)++;
}
