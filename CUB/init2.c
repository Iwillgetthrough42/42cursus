#include "lib.h"

void eastwest(t_all *all)
{
	if (all->pl.dir == 'E')
	{
		all->pl.diry = 0;
		all->pl.dirx = 1;
		all->pl.planex = 0;
		all->pl.planey = 0.66;
	}
	else if (all->pl.dir == 'W')
	{
		all->pl.diry = 0;
		all->pl.dirx = -1;
		all->pl.planex = 0;
		all->pl.planey = -0.66;
	}

}

void northsouth(t_all *all)
{
	if (all->pl.dir == 'S')
	{
		all->pl.diry = 1;
		all->pl.dirx = 0;
		all->pl.planex = -0.66;
		all->pl.planey = 0;
	}
	else if (all->pl.dir == 'N')
	{
		all->pl.diry = -1;
		all->pl.dirx = 0;
		all->pl.planex = 0.66;
		all->pl.planey = 0;
	}
}

void create_data(t_all *all)
{
	eastwest(all);
	northsouth(all);
	all->tex.width = 64;
	all->tex.height = 64;
}