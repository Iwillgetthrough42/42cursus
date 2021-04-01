#include "lib.h"

void initpl(t_player *pl)
{
	pl->x = 0;
	pl->y = 0;
	pl->dirx = 0;
	pl->diry = 0;
	pl->planex = 0;
	pl->planey = 0;
	pl->mapx = 0;
	pl->mapy = 0;
	pl->dir = 0;
}

void initray(t_ray *ray)
{
	ray->camerax = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deldistx = 0;
	ray->deldisty = 0;
	ray->walldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
}

void inittex(t_tex *tex)
{
	tex->imge = 0;
	tex->imgw = 0;
	tex->imgs = 0;
	tex->imgn = 0;
	tex->width = 0;
	tex->height = 0;
	tex->texx = 0;
	tex->texy = 0;
	tex->step = 0;
	tex->texpos = 0;
	tex->color = 0;
}