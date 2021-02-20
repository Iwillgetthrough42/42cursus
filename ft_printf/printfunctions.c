/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctionc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:28:23 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/17 17:52:41 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "libft/libft.h"

void	printchar(va_list args, t_fields *st)
{
	char c;

	c = va_arg(args, int);
	if (!st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ');
	else if (!st->minus && st->zero && st->width)
		printch(st->width - 1, '0');
	write(1, &c, 1);
	if (st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ');
}

void	printdigit(char c, va_list args, t_fields *st)
{
	char	*str;
	long	num;

	if (c == 'i' || c == 'd')
	{
		num = va_arg(args, int);
		str = ft_itoa(num);
	}
	else if (c == 'u')
	{
		num = va_arg(args, unsigned int);
		str = ft_itoa(num);
	}
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
	else if (!st->minus && st->zero && st->width)
		printch(st->width - ft_strlen(str), '0');
	if (st->precision)
		printch(st->precision - ft_strlen(str),'0');
	write(1, str, ft_strlen(str));
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
}

void	printstr(va_list args, t_fields *st)
{
	char *str;

	str = va_arg(args, char *);
	if (st->precision)
		str = ft_substr(str, 0, st->precision);
	if (!st->minus && !st->zero && st->width)
			printch(st->width - ft_strlen(str),' ');
	write(1, str, ft_strlen(str));
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
}

void	printhex(char c, va_list args, t_fields *st)
{
	unsigned long	n;
	char			*str;

	n = va_arg(args, unsigned int);
	if (c == 'x')
		str = ft_anybase(n, "0123456789abcdef");
	else if (c == 'X')
		str = ft_anybase(n, "0123456789ABCDEF");
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
	else if (!st->minus && st->zero && st->width)
		printch(st->width - ft_strlen(str), '0');
	if (st->precision)
		printch(st->precision - ft_strlen(str),'0');
	write(1, str, ft_strlen(str));
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
}

void	printpointer(va_list args, t_fields *st)
{
	unsigned long	n;
	char			*str;

	n = va_arg(args, unsigned long);
	str = ft_anybase(n, "0123456789abcdef");
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ');
}



