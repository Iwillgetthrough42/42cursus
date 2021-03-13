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

void	checkline(char *line, t_mapdata *data, int cnt)
{
	int i;

	i = 0;
	while (*line != '\0')
	{
		if (*line == 'R' && *(line + 1) == ' ')
			ft_res(&line, data);
		else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
			ft_dir(&line, &data->north);
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			ft_dir(&line, &data->south);
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			ft_dir(&line, &data->west);
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			ft_dir(&line, &data->east);
		else if (line[i] == 'S' && line[i + 1] == ' ')
			ft_dir(&line, &data->sprite);
		else if (line[i] == 'F' && line[i + 1] == ' ')
			ft_color(&line, &data->floor);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			ft_color(&line, &data->ceilling);
		else if(line[i] == '1')
			ft_map(&line, data, cnt);
	}
}

void	readfile()
{
	int			fd;
	char		*line;
	t_mapdata	data;
	int			t;
	int 		cnt;

	cnt = ft_count();
	t = 1;
	init(&data);
	fd = open("map.cub", O_RDONLY);
	while (t)
	{
		t = get_next_line(fd, &line);
		skipspaces(&line);
		checkline(line, &data, cnt);
	}
}

int		main()
{
	readfile();
}