#include "lib.h"

void 	generatespr(t_all *all)
{
	if (!(all->spr.img = mlx_xpm_file_to_image(all->data.mlx, all->data.sprite,\
	 &all->spr.width, &all->spr.height)))
	{
		free(all->spr.sprx);
		free(all->spr.spry);
		free(all->spr.zbuffer);
		ft_error4(&all->data);
	}
	all->spr.img = mlx_get_data_addr(all->spr.img, &all->img.bits, \
	 &all->img.linel, &all->img.endian);
	all->spr.color = (int *)all->spr.img;
}

void	draw(t_all *all)
{
	int i;
	int y;
	int d;
	int color;

	i = all->spr.drawstx;
	while (i < all->spr.drawendx)
	{
		all->spr.texx = (int) (256 * (i - (-all->spr.spritewidth / 2 + \
			all->spr.spritescreenx)) * 64 / all->spr.spritewidth) / 256;
		if (all->spr.transformy > 0 && i > 0 && i < all->data.resx &&\
			all->spr.transformy < all->spr.zbuffer[i])
			y = all->spr.drawsty;
		while (y < all->spr.drawendy)
		{
			d = y * 256 - all->data.resy * 128 + all->spr.spriteheight * 128;
			all->spr.texy = ((d * 64) / all->spr.spriteheight) / 256;
			if ((all->spr.color[64 * all->spr.texy + all->spr.texx] \
				& 0x00FFFFFF) != 0)
				all->img.addr[y * all->data.resx + i] =\
				all->spr.color[64 * all->spr.texy + all->spr.texx];
			y++;
		}
		i++;
	}
}

void	calcst(t_all *all)
{		
	all->spr.drawsty = -all->spr.spriteheight / 2 + all->data.resy / 2;
	if (all->spr.drawsty < 0)
		all->spr.drawsty = 0;
	all->spr.drawendy = all->spr.spriteheight / 2 + all->data.resy / 2;
	if (all->spr.drawendy >= all->data.resy)
		all->spr.drawendy = all->data.resy - 1;
	all->spr.spritewidth = abs((int)(all->data.resy / all->spr.transformy));
	all->spr.drawstx = -all->spr.spritewidth / 2 + all->spr.spritescreenx;
	if (all->spr.drawstx < 0)
		all->spr.drawstx = 0;
	all->spr.drawendx = all->spr.spritewidth / 2 + all->spr.spritescreenx;
	if (all->spr.drawendx >= all->data.resx)
		all->spr.drawendx = all->data.resx - 1;
	draw(all);
}