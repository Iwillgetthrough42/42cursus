#include "lib.h"

void verline(t_all *all, int x)
{
	int y;

	y = all->ray.drawstart;
	while (y < all->ray.drawend)
	{
		all->tex.texy = (int)all->tex.texpos & (all->tex.height - 1);
		all->tex.texpos += all->tex.step;
		//mlx_pixel_put(all->data.mlx, all->data.mlx_win, y, x, all->tex.color[all->tex.texy * all->tex.height + all->tex.texx]);
		y++;
	}
}

void calcdistheight(t_all *all)
{
	if (all->ray.side == 0)
			all->ray.walldist = (all->pl.mapx - all->pl.x + (1 - all->ray.stepx) / 2) / all->ray.raydirx;
	else
		all->ray.walldist = (all->pl.mapy - all->pl.y + (1 - all->ray.stepy) / 2) / all->ray.raydiry;
	all->ray.lineheight = (int)(all->data.resy / all->ray.walldist);
	all->ray.drawstart = -all->ray.lineheight / 2 + all->data.resy / 2;
	if (all->ray.drawstart < 0)
		all->ray.drawstart = 0;
	all->ray.drawend = all->ray.lineheight / 2 + all->data.resy / 2;
	if (all->ray.drawend >= all->data.resy)
		all->ray.drawend = all->data.resy - 1;
}