#include "lib.h"
#include <stdio.h>

int 			bnear(t_mapdata *data, int i, int j)
{
	int st;
	if (i != 0 && j != 0 && i != data->mapy - 1)
	{
		st = j - 1;
		while (st > 0)
		{
			if ((data->map[i + 1][st] != '1' && !ft_isspace(data->map[i + 1][st]))\
		 	|| (data->map[i - 1][st] != '1' && !ft_isspace(data->map[i - 1][st])))
				return (0);
			st--;
		}
	}
	return (1);
}

int 			etool(t_mapdata *data, int i, int ind, int index)
{
	int st;

	if (i != 0 && i != data->mapy - 1)
	{
		st = ind + 1;
		while (st < ft_strlen(data->map[index]) - 1)
		{
			if (data->map[index][st] != '1' && !ft_isspace(data->map[index][st]))\
				return (0);
			st++;
		}
	}
	return (1);
}

int 			enear(t_mapdata *data, int i, int ind)
{
	return (etool(data, i, ind, i + 1));
	return (etool(data, i, ind, i - 1));
}

int 			nearlst(t_mapdata *data, int ind, int j)
{
	int st;
	int c;
	int c2;

	if (ind != data->mapy - 1 && j != 0)
	{
		
		st = ind + 1;
		while (st < data->mapy)
		{
			c = j + 1;
			c2 = j - 1;
			while (ft_isspace(data->map[st][c]))
				c++;
			while (ft_isspace(data->map[st][c2]))
				c2--;
			if ((data->map[st][c] != '1' && !ft_isspace(data->map[st][c]))
			|| (data->map[st][c2] != '1' && !ft_isspace(data->map[st][c2])))
				return (0);
			st++;
		}
	}
	return (1);

}

int				nearrow(t_mapdata *data, int ind, int j)
{
	int st;
	int c;
	int c2;

	if (ind != 0 && j != 0)
	{
		st = ind - 1;
		while (st > 0)
		{
			c = j + 1;
			c2 = j - 1;
			while (ft_isspace(data->map[st][c]))
				c++;
			while (ft_isspace(data->map[st][c2]))
				c2--;
			if ((data->map[st][c] != '1' && !ft_isspace(data->map[st][c]))
			|| (data->map[st][c2] != '1' && !ft_isspace(data->map[st][c2])))
				return (0);
			st--;
		}
	}
	return (1);
}
