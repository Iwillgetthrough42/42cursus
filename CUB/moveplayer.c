#include "lib.h"

void	moveplayerup(t_pladata *param)
{
	if (param->data->map[param->player->i - 1][param->player->j] != '1')
	{
		param->data->map[param->player->i - 1][param->player->j] \
		= param->data->map[param->player->i][param->player->j];
		param->data->map[param->player->i][param->player->j] = '0';
	}
}

void	moveplayerleft(t_pladata *param)
{
	if (param->data->map[param->player->i][param->player->j - 1] != '1')
	{
		param->data->map[param->player->i][param->player->j - 1] \
		= param->data->map[param->player->i][param->player->j];
		param->data->map[param->player->i][param->player->j] = '0';
	}
}

void	moveplayerright(t_pladata *param)
{
	if (param->data->map[param->player->i][param->player->j + 1] != '1')
	{
		param->data->map[param->player->i][param->player->j + 1] \
		= param->data->map[param->player->i][param->player->j];
		param->data->map[param->player->i][param->player->j] = '0';
	}
}

void	moveplayerdown(t_pladata *param)
{
	if (param->data->map[param->player->i + 1][param->player->j] != '1')
	{
		param->data->map[param->player->i + 1][param->player->j] \
		= param->data->map[param->player->i][param->player->j];
		param->data->map[param->player->i][param->player->j] = '0';
	}
}