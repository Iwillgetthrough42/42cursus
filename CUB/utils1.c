#include "lib.h"

int		checkmalloc(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i])
	{
		i++;
	}
	return (i);
}

static	int	resxy(char **line, t_mapdata *data)
{
	int		i;
	char	*str1;
	int		count1;

	i = 0;
	skipspaces(line);
	count1 = checkmalloc(*line);
	str1 = malloc(sizeof(char) * (count1 + 1));
	while (**line != ' ' && **line)
	{
		str1[i] = **line;
		(*line)++;
		i++;
	}
	return (ft_atoi(str1));
}

void	ft_res(char *line, t_mapdata *data)
{

	line++;
	data->resx = resxy(&line, data);
	data->resy = resxy(&line, data);
}