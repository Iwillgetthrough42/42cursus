#include "lib.h"
#include <stdio.h>

void	keyupdn(int keycode, t_all *all)
{
	if (keycode == 13)
	{	if (all->data.map[(int)(all->pl.y + all->pl.diry * all->pl.movespeed)]\
			[(int)all->pl.x] == '0')
			all->pl.y += all->pl.diry * all->pl.movespeed;
		if (all->data.map[(int)(all->pl.y)]\
			[(int)(all->pl.x + all->pl.dirx * all->pl.movespeed)] == '0')
			all->pl.x += all->pl.dirx * all->pl.movespeed;
	}
	else if (keycode == 1)
	{
		if (all->data.map[(int)(all->pl.y - all->pl.diry * all->pl.movespeed)]\
		[(int)all->pl.x] == '0')
			all->pl.y -= all->pl.diry * all->pl.movespeed;
		if (all->data.map[(int)(all->pl.y)]\
			[(int)(all->pl.x - all->pl.dirx * all->pl.movespeed)] == '0')
			all->pl.x -= all->pl.dirx * all->pl.movespeed;
	}
}

void	keyrot1(t_all *all)
{
	double	olddirx;
	double 	oldplanex;

	olddirx = all->pl.dirx;
	all->pl.dirx = all->pl.dirx * cos(-0.0628) - all->pl.diry * sin(-0.0628);
	all->pl.diry = all->pl.dirx * sin(-0.0628) + all->pl.diry * cos(-0.0628);
	all->pl.planex = all->pl.planex * cos(-0.0628) - all->pl.planey * sin(-0.0628);
	all->pl.planey = all->pl.planex * sin(-0.0628) + all->pl.planey * cos(-0.0628);
}

void	keyrot2(t_all *all)
{
	double	olddirx;
	double 	oldplanex;

	olddirx = all->pl.dirx;
	all->pl.dirx = all->pl.dirx * cos(0.0628) - all->pl.diry * sin(0.0628);
	all->pl.diry = all->pl.dirx * sin(0.0628) + all->pl.diry * cos(0.0628);
	all->pl.planex = all->pl.planex * cos(0.0628) - all->pl.planey * sin(0.0628);
	all->pl.planey = all->pl.planex * sin(0.0628) + all->pl.planey * cos(0.0628);
}

int 	keyesc(t_all *all)
{
	free(all->spr.zbuffer);
	free(all->spr.sprx);
	free(all->spr.spry);
	ft_free(&all->data);
	exit(0);
	return (1);
}

int 	ft_key(int keycode, t_all *all)
{
	keyupdn(keycode, all);
	if (keycode == 0 || (keycode == 0 && keycode == 13))
		keyrot1(all);
	if (keycode == 2 || (keycode == 0 && keycode == 13))
		keyrot2(all);
	if (keycode == 53)
		keyesc(all);
	if (keycode != 53)
	{
		mlx_clear_window(all->data.mlx, all->data.mlx_win);
		logic(all);
	}
	return (0);
}