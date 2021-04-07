#include "lib.h"

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || 
		 c == '\f' || c == '\r' || c == ' ' || c == 0);
}


void 	firstrow(t_mapdata *data)
{
	int j;
	int ind;

	j = 0;
	while (ft_isspace(data->map[0][j]))
		j++;
	while (j < ft_strlen(data->map[0]))
	{
		ind = 0;
		while (ft_isspace(data->map[ind][j]))
			ind++;
		if (!ft_isspace(data->map[ind][j]) && 
			data->map[ind][j] != '1')
			ft_error2(data);
		j++;
	}
}

void 	lastrow(t_mapdata *data)
{
	int j;
	int ind;

	j = 0;
	while (ft_isspace(data->map[data->mapy - 1][j]))
		j++;
	while (j < ft_strlen(data->map[data->mapy - 1]))
	{
		ind = data->mapy - 1;
		while (ft_isspace(data->map[ind][j]))
			ind--;
		if (!ft_isspace(data->map[ind][j]) && 
			data->map[ind][j] != '1')
			ft_error2(data);
		j++;
	}	

}