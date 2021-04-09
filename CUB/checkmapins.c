#include "lib.h"

int		findlastrow(t_mapdata *data, int j)
{
	int i;
	int ind;

	i = 0;
	while (i < data->mapy)
	{
		ind = i;
		if (ind == data->mapy - 1)
		{
			while (ft_isspace(data->map[ind][j]))
				ind--;
			return (ind);
		}
		i++;
	}
	return (0);
}

int 	findfirstrow(t_mapdata *data, int j)
{
	int i;
	int ind;

	i = 0;
	while (i < data->mapy)
	{
		ind = i;
		if (ind == 0)
		{
			while (ft_isspace(data->map[ind][j]))
				ind++;
			return (ind);
		}
		i++;
	}
	return (0);
}

int ft_bool(t_mapdata *data, int ind, int j)
{
	return (data->map[ind][j] != '1' &&
			data->map[ind][j] != '0' &&
			data->map[ind][j] != '2' &&
			data->map[ind][j] != 'N' &&
			data->map[ind][j] != 'W' &&
			data->map[ind][j] != 'S' &&
			data->map[ind][j] != ' ' &&
			data->map[ind][j] != 'E' );
}

void	checkmapins(t_mapdata *data)
{
	int i;
	int j;
	int ind;
	int lstcol;

	i = 0;
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
			ind = i;
			if (ind > findfirstrow(data, j) && ind < findlastrow(data, j))
				if (ft_bool(data, ind, j))
					ft_error3(data);
			j++;
		}
		i++;
	}
}