/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:13:18 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 15:18:23 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef	struct		s_data
{
	void	*img;
	int		*addr;
	int		bits;
	int		linel;
	int		endian;
}					t_data;

typedef	struct		s_tex
{
	void	*imge;
	void	*imgw;
	void	*imgn;
	void	*imgs;
	int		width;
	int		height;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
	int		*color;
}					t_tex;

typedef	struct		s_mapdata
{
	int		resx;
	int		resy;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor;
	int		ceilling;
	char	**map;
	int		mapy;
	void	*mlx;
	void	*mlx_win;
	char	*file;
}					t_mapdata;

typedef	struct		s_player
{
	double	x;
	double	y;
	char	dir;
	int		mapx;
	int		mapy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
}					t_player;

typedef	struct		s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deldistx;
	double	deldisty;
	double	walldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}					t_ray;

typedef	struct		s_sprite
{
	double	*zbuffer;
	double	*sprx;
	double	*spry;
	int		num;
	double	spritex;
	double	spritey;
	double	inv;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		texx;
	int		texy;
	int		drawstx;
	int		drawsty;
	int		drawendx;
	int		drawendy;
	void	*img;
	int		*color;
	int		width;
	int		height;
}					t_sprite;

typedef struct		s_all
{
	t_ray		ray;
	t_player	pl;
	t_mapdata	data;
	t_tex		tex;
	t_data		img;
	t_sprite	spr;
}					t_all;

void				skipspaces(char **line);
void				ft_res(char **line, t_mapdata *data, int *i);
int					ft_dir(char **line, char **st, int *l);
int					getcolor(char **line, t_mapdata *data);
int					createtrgb(int r, int g, int b);
char				*ft_anybase(unsigned long n, const char *base);
void				ft_map(char **line, t_mapdata *data);
int					ft_count();
int					readfile(t_mapdata *data);
void				findplayer(t_mapdata *data, t_player *player);
void				initpl(t_player *pl);
void				initray(t_ray *ray);
void				inittex(t_tex *tex);
void				create_data(t_all *all);
void				calcdistheight(t_all *all);
void				texture(t_all *all);
void				generate_textures(t_all *all);
void				color(t_all *all);
void				verline(t_all *all, int x);
void				initdata(t_all *all);
void				ft_error1(t_mapdata *data);
void				ft_error2(t_mapdata *data);
int					ft_isspace(int c);
void				checkmapins(t_mapdata *data);
void				ft_error3(t_mapdata *data);
void				ft_error4(t_mapdata *data);
void				ft_free(t_mapdata *data);
void				ft_color(char **line, int *st, int *l, t_mapdata *data);
int					ft_key(int keycode, t_all *all);
void				logic(t_all *all);
int					keyesc(t_all *all);
void				initsprite(t_all *all);
void				findsprites(t_all *all);
void				sprite(t_all *all);
void				calcst(t_all *all);
void				generatespr(t_all *all);
int					ft_bool1(t_mapdata *data, int ind, int j);
void				start(char *file, t_all *all);
void				screenshot(t_all *all);
int					main(int argc, char **argv);

#endif
