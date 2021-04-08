#include "lib.h"

void	findplayer(t_mapdata *data, t_player *player)
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
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				player->dir = data->map[i][j];
				player->y = i;
				player->x = j;
			}
			j++;
		}
		i++;
	}
}

void 	color(t_all *all)
{
	if (all->ray.side == 1 && (all->pl.mapy > all->pl.y))
		all->tex.color = (int *)(all->tex.imgs);
	else if (all->ray.side == 1 && (all->pl.mapy < all->pl.y))
		all->tex.color = (int *)(all->tex.imgn);
	else if (all->ray.side == 0 && (all->pl.mapx > all->pl.x))
		all->tex.color = (int *)(all->tex.imge);
	else
		all->tex.color = (int *)(all->tex.imgw);
}

void	texture(t_all *all)
{
	double wallx;

	if (all->ray.side == 0)
		wallx = all->pl.y + all->ray.walldist * all->ray.raydiry;
	else
		wallx = all->pl.x + all->ray.walldist * all->ray.raydirx;
	wallx -= floor(wallx);
	all->tex.texx = (int)(wallx * all->tex.height);
	if (all->ray.side == 0 && all->ray.raydirx > 0)
		all->tex.texx = all->tex.width - all->tex.texx - 1;
	if (all->ray.side == 1 && all->ray.raydiry < 0)
		all->tex.texx = all->tex.width - all ->tex.texx - 1;
	all->tex.step = 1.0 * all->tex.height / all->ray.lineheight;
	all->tex.texpos = (all->ray.drawstart - all->data.resy / 2 + all->ray.lineheight / 2) 
	* all->tex.step;
}

int 	create_textures(t_all *all)
{
	if (!(all->tex.imge = mlx_xpm_file_to_image(all->data.mlx, all->data.east,\
	 &all->tex.width, &all->tex.height)))
		ft_error4(&all->data);
	if (!(all->tex.imgw = mlx_xpm_file_to_image(all->data.mlx, all->data.west,\
	 &all->tex.width, &all->tex.height)))
		ft_error4(&all->data);
	if (!(all->tex.imgn = mlx_xpm_file_to_image(all->data.mlx, all->data.north,\
	 &all->tex.width, &all->tex.height)))
		ft_error4(&all->data);
	if (!(all->tex.imgs = mlx_xpm_file_to_image(all->data.mlx, all->data.south,\
	 &all->tex.width, &all->tex.height)))
		ft_error4(&all->data);
	return (1);
}

void	generate_textures(t_all *all)
{
	create_textures(all);
	all->tex.imge = mlx_get_data_addr(all->tex.imge, &all->img.bits, \
	 &all->img.linel, &all->img.endian);
	all->tex.imgw = mlx_get_data_addr(all->tex.imgw, &all->img.bits, \
	 &all->img.linel, &all->img.endian);
	all->tex.imgn = mlx_get_data_addr(all->tex.imgn, &all->img.bits, \
	 &all->img.linel, &all->img.endian);
	all->tex.imgs = mlx_get_data_addr(all->tex.imgs, &all->img.bits, \
	 &all->img.linel, &all->img.endian);
}