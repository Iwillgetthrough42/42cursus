/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:25:41 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/23 17:49:54 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"

void	printch(int quant, char ch, t_fields *st)
{
	int		i;

	i = 0;
	while (i < quant)
	{
		write(1, &ch, 1);
		st->len += 1;
		i++;
	}
}

void	ft_putstr(char *str, t_fields *st)
{
	write(1, str, ft_strlen(str));
	st->len += ft_strlen(str);
}
