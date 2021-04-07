#include "lib.h"

void 	ft_free(t_mapdata *data)
{
	int i;

	i = 0;
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
	if (data->map)
	{
		while (i < data->mapy)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void 	ft_error1(t_mapdata *data)
{
	ft_free(data);
	printf("Error\nwrong map fields");
	exit(0);
}

void 	ft_error2(t_mapdata *data)
{
	ft_free(data);
	printf("Error\nwrong map walls");
	exit(0);
}

void 	ft_error3(t_mapdata *data)
{
	ft_free(data);
	printf("Error\nwrong map symbols");
	exit(0);
}