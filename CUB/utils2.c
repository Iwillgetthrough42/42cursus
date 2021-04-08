#include "lib.h"

static	int		checkmalloc(char *line)
{
	int i;

	i = 0;
	while (line[i] != ',' && line[i])
	{
		i++;
	}
	return (i);
}

int				getcolor(char **line, t_mapdata *data)
{
	char	*str;
	int		i;

	i = 0;
	while (**line == ',')
		(*line)++;
	while (**line == ' ')
		(*line)++;
	if (!(str = malloc(sizeof(char) * (checkmalloc(*line) + 1))))
		return (0);
	while (**line != ',' && **line)
	{
		str[i] = **line;
		(*line)++;
		i++;
	}
	str[i] = '\0';
	if (str[0] == '\0')
	{
		ft_free(data);
		write(1, "error\nwrong color fields", 23);
		exit(0);
	}
	return (ft_atoi(str));
}

int				createtrgb(int r, int g, int b)
{
	int t;

	t = 100;
	return(t << 24 | r << 16 | g << 8 | b);
}