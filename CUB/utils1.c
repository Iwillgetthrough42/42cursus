#include "lib.h"
#include <stdio.h>

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
	str1[i] = '\0';
	return (ft_atoi(str1));
}

void	ft_res(char **line, t_mapdata *data)
{
	(*line)++;
	data->resx = resxy(line, data);
	data->resy = resxy(line, data);
}

void	ft_dir(char **line, char **st)
{
	char	*str;
	int 	count;
	int		i;

	i = 0;
	(*line)++;
	(*line)++;
	skipspaces(line);
	count = checkmalloc(*line);
	str = malloc(sizeof(char) * (count + 1));
	while (**line != ' ' && **line)
	{
		str[i] = **line;
		(*line)++;
		i++;
	}
	str[i] = '\0';
	*st = ft_strdup(str);
	free(str);
	str = NULL;
}

void	ft_color(char **line, int *st[3])
{
	int	i;

	//*st = malloc(sizeof(char) * 3);
	i = 0;
	(*line)++;
	skipspaces(line);
	while (i < 3)
	{
		*st[i] = getcolor(line);
		i++;
	}
}






