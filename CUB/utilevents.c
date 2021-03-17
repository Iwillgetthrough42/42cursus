#include "lib.h"
#include <stdio.h>

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
				player->i = i;
				player->j = j;
			}
			j++;
		}
		i++;
	}


}

int		deal_key(int key, t_pladata *param)
{
	if (key == 126)
		moveplayerup(param);
	else if (key == 123)
		moveplayerleft(param);
	else if (key == 124)
		moveplayerright(param);
	else if (key == 125)
		moveplayerdown(param);
	mlx_clear_window(param->mlx, param->win);
	drawmap(param->data, param->player, param->mlx, param->win);
	return (0);
}