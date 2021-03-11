#include "lib.h"
#include <stdio.h>

void	skipspaces(char **line)
{
	while (**line == '\t' || **line == '\n' || **line == '\v' || 
		 **line == '\f' || **line == '\r' || **line == ' ')
			(*line)++;
}

void	checkline(char *line, t_mapdata *data)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			ft_res(line, data);
		/*else if (line[i] == 'N' && line[i + 1] == 'O')
			ft_north(line, data);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			ft_south(line, data);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			ft_west(line, data);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			ft_east(line, data);
		else if (line[i] == 'S')
			ft_sprite(line, data);
		else if (line[i] == 'S')
			ft_floor(line, data);
		else if (line[i] == 'S')
			ft_ceilling(line, data);*/
		i++;
	}
}

void	readfile()
{
	int			fd;
	char		*line;
	t_mapdata	data;
	int			t;

	t = 1;	
	fd = open("map.cub", O_RDONLY);
	//while (t)
	//{
		get_next_line(fd, &line);
		skipspaces(&line);
		checkline(line, &data);
		printf("%s, %d", line, data.resx);
	//}
}

int		main()
{
	readfile();
}