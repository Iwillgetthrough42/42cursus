#ifndef LIB_H
#define LIB_H

#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

typedef	struct		s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		linel;
	int		endian;
}					t_data;	

typedef	struct		s_mapdata
{
	int		resx;
	int		resy;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor[3];
	int		*ceilling;
	char	**map;
}					t_mapdata;

void				skipspaces(char **line);
void				ft_res(char **line, t_mapdata *data);
void				skipspaces(char **line);
void				ft_dir(char **line, char **st);
int					getcolor(char **line);
void				ft_color(char **line, int *st[3]);

#endif
