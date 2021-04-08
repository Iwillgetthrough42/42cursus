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
	write(1, "Error\nwrong map fields", 22);
	exit(0);
}

void 	ft_error2(t_mapdata *data)
{
	ft_free(data);
	write(1,"Error\nwrong map walls", 21);
	exit(0);
}

void 	ft_error3(t_mapdata *data)
{
	ft_free(data);
	write(1, "Error\nwrong map symbols", 23);
	exit(0);
}

void	ft_error4(t_mapdata *data)
{
	ft_free(data);
	write(1, "Error\nTexture Path is Wrong", 26);
	exit(0);
}