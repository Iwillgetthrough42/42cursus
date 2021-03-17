/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:40:20 by arastepa          #+#    #+#             */
/*   Updated: 2021/03/07 19:12:58 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void	drawcircle(void *mlx, void *win, int r, int a, int b)
{
	int i;
	int j;
	int n;
	int x;
	int y;

	n = 2*r;
	i = a;
	j = b;
	while (i <= a + n)
	{
		j = b;
		while (j <= b + n)
		{
			x = i - r;
			y = j - r;
			if (((x - a) * (x - a) + (y - b) * (y - b)) <= r*r)
				mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	drawrect(void *mlx, void *win, int x, int y)
{
	int i;
	int j;

	i = x;
	j = y;
	while (i <= x + 32)
	{
		j = y;
		while (j <= y + 32)
		{
			mlx_pixel_put(mlx, win, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
}

void	drawmap(t_mapdata *data, t_player *player, void *mlx, void *win)
{

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->mapy)
	{
		j = 0;
		while(j < ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == '1')
				drawrect(mlx, win, j*32, i*32);
			else
			{
				findplayer(data, player);			
				drawcircle(mlx, win, 5, player->j * 32, player->i * 32);
			}
			j++;
		}
		i++;
	}

}

int		main()
{
	void		*mlx;
	void		*mlx_win;
	t_mapdata	data;
	t_player	player;
	t_pladata	pl;
	
	data =readfile();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "JUMANJI");
	drawmap(&data, &player, mlx, mlx_win);
	pl.data = &data;
	pl.player = &player;
	pl.mlx = mlx;
	pl.win = mlx_win;
	mlx_key_hook(mlx_win, deal_key, &pl);
	mlx_loop(mlx);
}
