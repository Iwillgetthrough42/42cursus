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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->linel + x * (data->bits / 8));
    *(unsigned int*)dst = color;
}

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
			//x = i - r;
			//y = j - r;
			//if (((x - a) * (x - a) + (y - b) * (y - b)) <= r*r)
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
			mlx_pixel_put(mlx, win, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	drawmap(t_mapdata *data, void *mlx, void *win)
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

			j++;
		}
		i++;
	}

}

int		main()
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_mapdata	data;
	
	data =readfile();
	//printf("%s", data.map[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "JUMANJI");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits, &img.linel, &img.endian);
	drawmap(&data, mlx, mlx_win);
	//drawcircle(mlx, mlx_win, 10, 960, 540);
	//mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
