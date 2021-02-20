/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:02:01 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/20 13:10:38 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"
#include <stdio.h>

void	init_struct(t_fields *st)
{
	st->minus = 0;
	st->zero = 0;
	st->precision = 0;
	st->width = 0;
	st->dot = 0;
}

void	handle_signs(char c, va_list args, t_fields *st)
{
	if (c == 'c')
		printchar(args, st);
	else if (c == 'd' || c == 'i' || c == 'u')
		printdigit(c, args, st);
	else if (c == 's')
		printstr(args, st);
	else if (c == 'x' || c == 'X')
		printhex(c, args, st);
	else if (c == 'p')
		printpointer(args, st);
}

void	check_sign(char **str, va_list args, t_fields *st)
{
	char	*signs;
	int		j;

	(*str)++;
	j = 0;
	check_flags(str, st);
	check_width(str, st, args);
	check_precision(str, st, args);
	signs = ft_strdup("cspdiuxX");
	while (signs[j] != '\0')
	{
		if (**str == signs[j])
		{
			handle_signs(signs[j], args, st);
			break ;
		}
		j++;	
	}
	if (**str == '%')
	{
		if (!st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ');
		else if (!st->minus && st->zero && st->width)
		printch(st->width - 1, '0');
		write(1, "%", 1);
		if (st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ');
	}
}

int		ft_printf(const char *s, ...)
{
	int		i;
	char	*str;
	va_list args;

	str = (char *)s;
	t_fields st;
	i = 0;
	va_start(args, s);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			init_struct(&st);
			check_sign(&str, args, &st);
		}
		else
			write(1, str, 1);
		str++;
	}
	return (1);
}