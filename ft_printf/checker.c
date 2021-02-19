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
	while (**str == '-' || **str == '+')
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
		(*str)++;
		if (**str == '*')
		{
			st->precision = va_arg(args, int);
			(*str)++;
		}
		while (**str >= '0' && **str <= '9')
		{
			st->precision = (st->width * 10) + (**str - 0);
			(*str)++;
		}

	}
	
}
