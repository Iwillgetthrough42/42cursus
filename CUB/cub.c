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

#include "mlx/mlx.h"
#include "lib.h"



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
		j = 0;
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

int		main()
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "JUMANJI");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits, &img.linel, &img.endian);
	drawcircle(mlx, mlx_win, 10, 960, 540);
	//mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
