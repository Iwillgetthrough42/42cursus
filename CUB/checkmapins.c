/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:06:56 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 13:07:01 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int 	ft_bool1(t_mapdata *data, int ind, int j)
{
	int t;

	t = 0;
	if (ind != 0 && ind != data->mapy - 1)
		if 	(data->map[ind - 1][j] != ' ' &&
			data->map[ind + 1][j] != ' ')
			t = 1;
	if (j != 0 && j != ft_strlen(data->map[ind]) - 1)
		if (data->map[ind][j + 1] != ' ' &&
			data->map[ind][j - 1] != ' ' && t == 1)
			return (1);
	return (0);
}


int 	ft_bool(t_mapdata *data, int ind, int j)
{
	return (data->map[ind][j] != '1' &&
			data->map[ind][j] != '0' &&
			data->map[ind][j] != '2' &&
			data->map[ind][j] != 'N' &&
			data->map[ind][j] != 'W' &&
			data->map[ind][j] != 'S' &&
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
			if (ft_bool1(data, i, j))
				if (ft_bool(data, i, j))
					ft_error3(data);
			j++;
		}
		i++;
	}
}
