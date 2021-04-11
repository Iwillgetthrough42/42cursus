#include "lib.h"

int		findmalloc(t_all *all)
{
	int i;
	int j;
	int l;

	l = 0;
	i = 0;
	j = 0;
	while (i < all->data.mapy)
	{
		j = 0;
		while(j < ft_strlen(all->data.map[i]))
		{
			if (all->data.map[i][j] == '2')
				l++;
			j++;
		}
		i++;
	}
	return (l);
}

void	findsprites(t_all *all)
{
	int i;
	int j;
	int l;

	all->spr.num = findmalloc(all);
	all->spr.sprx = malloc(sizeof(double) * findmalloc(all));
	all->spr.spry = malloc(sizeof(double) * findmalloc(all));
	l = 0;
	i = 0;
	j = 0;
	while (i < all->data.mapy)
	{
		j = 0;
		while(j < ft_strlen(all->data.map[i]))
		{
			if (all->data.map[i][j] == '2')
			{
				all->spr.sprx[l] = j;
				all->spr.spry[l] = i;
				l++;
			}
			j++;
		}
		i++;
	}
}

void 	sortsprites(t_all *all, int *spriteorder, double *spritedist)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < all->spr.num - 1)
	{
		j = i + 1;
		while (j < all->spr.num)
		{
			if (spritedist[i] < spritedist[j])
			{
				tmp = spriteorder[i];
				spriteorder[i] = spriteorder[j];
				spriteorder[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	calcsprite(t_all *all, int *spriteorder, double *spritedist)
{
	int i;
	
	i = 0;
	while (i < all->spr.num)
	{
		all->spr.spritex = all->spr.sprx[spriteorder[i]] - all->pl.x;
		all->spr.spritey = all->spr.spry[spriteorder[i]] - all->pl.y;
		all->spr.inv = 1.0 / (all->pl.planex * all->pl.diry - all->pl.dirx * \
			all->pl.planey);
		all->spr.transformx = all->spr.inv * (all->pl.diry * all->spr.spritex - \
			all->pl.dirx * all->spr.spritey);
		all->spr.transformy = all->spr.inv * (-all->pl.planey * all->spr.spritex + \
			all->pl.planex * all->spr.spritey);
		all->spr.spritescreenx = (int)((all->data.resx / 2) * \
			(1 + all->spr.transformx / all->spr.transformy));
		all->spr.spriteheight = abs((int)(all->data.resy / all->spr.transformy));
		calcst(all);
		i++;
	}
}

void	sprite(t_all *all)
{
	int 	i;
	int		spriteorder[all->spr.num];
	double	spritedist[all->spr.num];

	generatespr(all);
	i = 0;
	while (i < all->spr.num)
	{
		spriteorder[i] = i;
		spritedist[i] = ((all->pl.x - all->spr.sprx[i]) * (all->pl.x - all->spr.sprx[i])\
						+ (all->pl.y - all->spr.spry[i]) * (all->pl.y - all->spr.spry[i]));
		i++;
	}
	sortsprites(all, spriteorder, spritedist);
	calcsprite(all, spriteorder, spritedist);
}
