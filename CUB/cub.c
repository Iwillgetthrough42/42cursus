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
#include <math.h>
#include <stdio.h>

void cond(t_all *all)
{	
	
	if (all->ray.raydirx < 0)
	{
		all->ray.stepx = -1;
		all->ray.sidedistx = (all->pl.x - all->pl.mapx) * all->ray.deldistx;
		
	}
	else
	{
		all->ray.stepx = 1;
		all->ray.sidedistx = (all->pl.mapx + 1.0 - all->pl.x) * all->ray.deldistx;
	}
	if (all->ray.raydiry < 0)
	{
		all->ray.stepy = -1;
		all->ray.sidedisty = (all->pl.y - all->pl.mapy) * all->ray.deldisty;
	}
	else
	{
		all->ray.stepy = 1;
		all->ray.sidedisty = (all->pl.mapy + 1.0 - all->pl.y) * all->ray.deldisty;
	}
}

void initvar(t_all *all, int x)
{
	all->ray.camerax = 2 * x / (double)(all->data.resx) - 1;
	all->ray.raydirx = all->pl.dirx + all->pl.planex * all->ray.camerax;
	all->ray.raydiry = all->pl.diry + all->pl.planey * all->ray.camerax;
	all->pl.mapx = (int)all->pl.x;
	all->pl.mapy = (int)all->pl.y;
	all->ray.deldistx = (all->ray.raydiry == 0) ? 0 : ((all->ray.raydirx == 0) ? 1 : fabs(1 / all->ray.raydirx));
	all->ray.deldisty = (all->ray.raydirx == 0) ? 0 : ((all->ray.raydiry == 0) ? 1 :fabs(1 / all->ray.raydiry));
	all->ray.hit = 0;	
}

void incrray(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sidedistx < all->ray.sidedisty)
		{
			all->ray.sidedistx += all->ray.deldistx;
			all->pl.mapx += all->ray.stepx;
			all->ray.side = 0;

		}
		else
		{
			all->ray.sidedisty += all->ray.deldisty;
			all->pl.mapy += all->ray.stepy;
			all->ray.side = 1;
		}
		if (all->data.map[all->pl.mapy][all->pl.mapx] == '1')
			all->ray.hit = 1;
		
	}
}

void	logic(t_all *all)
{
	int x;

	x = 0;
	while (x < all->data.resx)
	{
		initvar(all, x);
		cond(all);
		incrray(all);
		calcdistheight(all);
		texture(all);
		color(all);
		verline(all, x);
		x++;
	}
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->img.img, 0, 0);
}

int		main()
{
	t_all 		all;

	all.data.mlx = mlx_init();
	readfile(&all.data);
	initpl(&all.pl);
	initray(&all.ray);
	inittex(&all.tex);
	initdata(&all);
	findplayer(&all.data, &all.pl);
	create_data(&all);
	all.data.mlx_win = mlx_new_window(all.data.mlx, all.data.resx, all.data.resy, "JUMANJI");
	generate_textures(&all);
	all.img.img = mlx_new_image(all.data.mlx, all.data.resx, all.data.resy);
	all.img.addr = (int *)mlx_get_data_addr(all.img.img, &all.img.bits, &all.img.linel, &all.img.endian);
	logic(&all);
	//mlx_hook(all.data.win, 2, 1L<<1, ft_key, &all);
	//mlx_loop(all.data.mlx);
}
