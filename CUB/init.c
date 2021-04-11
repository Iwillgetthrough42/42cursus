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
	pl->movespeed = 0.2;
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

void initdata(t_all *all)
{
	all->img.img = 0;
	all->img.addr = 0;
	all->img.bits = 0;
	all->img.linel = 0;
	all->img.endian = 0;
}

void initsprite(t_all *all)
{
	all->spr.zbuffer = malloc(sizeof(double) * all->data.resx);
	all->spr.sprx = 0;
	all->spr.spry = 0;
	all->spr.num = 0;
	all->spr.spritex = 0;
	all->spr.spritey = 0;
	all->spr.inv = 0;
	all->spr.transformx = 0;
	all->spr.transformy = 0;
	all->spr.spritescreenx = 0;
	all->spr.spriteheight = 0;
	all->spr.spritewidth = 0;
	all->spr.texx = 0;
	all->spr.texy = 0;
	all->spr.drawstx = 0;
	all->spr.drawsty = 0;
	all->spr.drawendx = 0;
	all->spr.img = 0;
	all->spr.color = 0;
}
