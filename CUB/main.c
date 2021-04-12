/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:18:39 by arastepa          #+#    #+#             */
/*   Updated: 2021/04/12 15:18:46 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int argc, char **argv)
{
	t_all 	all;
	int 	t; 			

	if (argc == 3)
		t = (ft_strlen(argv[2]) > ft_strlen("--save")) ?\
		 ft_strlen(argv[2]) : 6; 
	if (argc == 2)
	{
		start(argv[1], &all);
		mlx_hook(all.data.mlx_win, 2, 1L<<0, ft_key, &all);
		mlx_hook(all.data.mlx_win, 17, 0, keyesc, &all);
		mlx_do_key_autorepeaton(all.data.mlx);
		mlx_loop(all.data.mlx);
	}
	else if (argc == 3 && ft_memcmp(argv[2], "--save", t) == 0)
	{
		start(argv[1], &all);
		screenshot(&all);
	}
}
