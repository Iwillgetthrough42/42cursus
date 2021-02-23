/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:02:01 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/23 14:25:36 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"
#include <stdio.h>

void	printpercent(t_fields *st)
{
	if (!st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ', st);
	else if (!st->minus && st->zero && st->width)
		printch(st->width - 1, '0', st);
	printch(1, '%', st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ', st);
}

void	init_struct(t_fields *st)
{
	st->minus = 0;
	st->zero = 0;
	st->prec = 0;
	st->width = 0;
	st->dot = 0;
	st->len = 0;
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
		printpercent(st);
}

int		ft_printf(const char *s, ...)
{
	int		i;
	char	*str;
	va_list args;
	int 	count;

	count = 0;
	str = (char *)s;
	t_fields st;
	i = 0;
	va_start(args, s);
	while (*str != '\0')
	{
		init_struct(&st);
		if (*str == '%')
			check_sign(&str, args, &st);
		else
			printch(1, *str, &st);
		count += st.len;
		str++;
	}
	return (count);
}
