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
		printch(st->width - 1, ' ', st);
	else if (!st->minus && st->zero && st->width)
		printch(st->width - 1, '0', st);
	printch(1, c, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ', st);
}

void	printdigit(char c, va_list args, t_fields *st)
{
	char	*str;
	long	num;
	int		t;

	if (c == 'i' || c == 'd')
		num = va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	str = (num == 0 && st->dot ? "" : ft_utoa(num));
	t = num < 0 && st->dot ? 1 : 0;
	if (!st->minus && st->width && (!st->zero || (st->zero && st->dot)))
		printch(st->width - ((st->precision >= (int)ft_strlen(str)) ? st->precision + t : ft_strlen(str)), ' ', st);
	if (!st->minus && st->zero && st->width && !st->dot)
	{
		if (num < 0)
			printch(1, '-', st);
		printch(st->width - ft_strlen(str), '0', st);
	}
	if (st->dot)
	{
		if (num < 0)
			printch(1, '-', st);
		printch(st->precision - ft_strlen(str + t), '0', st);
	}
	if (num < 0 && ((st->zero && st->width) || (st->dot)))
		str++;
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - (st->precision > (int)ft_strlen(str) ? st->precision + t : ft_strlen(str) + t), ' ', st);
}

void	printstr(va_list args, t_fields *st)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
		if (st->dot)
			str = ft_substr(str, 0, st->precision);
		if (!st->minus && !st->zero && st->width)
			printch(st->width - ft_strlen(str),' ', st);
		ft_putstr(str, st);
		if (st->minus && !st->zero && st->width)
			printch(st->width - ft_strlen(str), ' ', st);
}	

void	printhex(char c, va_list args, t_fields *st)
{
	unsigned long	n;
	char			*str;
	char			*base;

	n = va_arg(args, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	str = (n == 0 && st->dot ? "" : ft_anybase(n, base));
	if (!st->minus && st->width && (!st->zero || (st->zero && st->dot)))
		printch(st->width - ((st->precision > (int)ft_strlen(str)) ? st->precision : ft_strlen(str)), ' ', st);
	else if (!st->minus && st->zero && st->width)
		printch(st->width - ft_strlen(str), '0', st);
	if (st->precision)
		printch(st->precision - ft_strlen(str),'0', st);
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - ((st->precision > (int)ft_strlen(str)) ? st->precision : ft_strlen(str)), ' ', st);
}

void	printpointer(va_list args, t_fields *st)
{
	unsigned long	n;
	char			*str;
	char			*tmp;

	n = va_arg(args, unsigned long);
	str = ft_anybase(n, "0123456789abcdef");
	tmp = str;
	if (n == 0)
		str = "0";
	str = ft_strjoin("0x",str);
	free(tmp);
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
}