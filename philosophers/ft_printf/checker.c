/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:25:28 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/18 18:39:00 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"

void	check_flags(char **str, t_fields *st)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			st->minus = 1;
		if (**str == '0')
			st->zero = 1;
		(*str)++;
	}
	if (st->minus && st->zero)
		st->zero = 0;
}

void	check_width(char **str, t_fields *st, va_list args)
{
	if (**str == '*')
	{
		st->width = va_arg(args, int);
		if (st->width < 0)
		{
			if (st->zero)
				st->zero = 0;
			st->width *= -1;
			st->minus = 1;
		}
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		st->width = (st->width * 10) + (**str - '0');
		(*str)++;
	}
}

void	check_precision(char **str, t_fields *st, va_list args)
{
	if (**str == '.')
	{
		st->dot = 1;
		(*str)++;
		if (**str == '*')
		{
			st->prec = va_arg(args, int);
			if (st->prec < 0)
			{
				st->prec = 0;
				st->dot = 0;
			}
			(*str)++;
		}
		while (**str >= '0' && **str <= '9')
		{
			st->prec = (st->prec * 10) + (**str - '0');
			(*str)++;
		}
	}
}
