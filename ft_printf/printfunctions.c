/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctionc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:28:23 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/23 17:37:30 by arastepa         ###   ########.fr       */
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
	int		cn;

	if (c == 'i' || c == 'd')
		num = va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	str = (num == 0 && st->dot ? "" : ft_utoa(num));
	t = num < 0 && st->dot ? 1 : 0;
	cn = st->prec >= (int)ft_strlen(str) ? 1 : 0;
	if (!st->minus && st->width && (!st->zero || (st->zero && st->dot)))
		printch(st->width - ((cn) ? st->prec + t : ft_strlen(str)), ' ', st);
	if (num < 0 && ((st->zero && st->width) || (st->dot)))
		printch(1, '-', st);
	if (!st->minus && st->zero && st->width && !st->dot)
		printch(st->width - ft_strlen(str), '0', st);
	if (st->dot)
		printch(st->prec - ft_strlen(str + t), '0', st);
	if (num < 0 && ((st->zero && st->width) || (st->dot)))
		str++;
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - (cn ? st->prec + t : ft_strlen(str) + t), ' ', st);
}

void	printstr(va_list args, t_fields *st)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (st->dot)
		str = ft_substr(str, 0, st->prec);
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
}

void	printhex(char c, va_list args, t_fields *st)
{
	unsigned long	n;
	char			*str;
	char			*base;
	int				cn;

	n = va_arg(args, unsigned int);
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	str = (n == 0 && st->dot ? "" : ft_anybase(n, base));
	cn = st->prec > (int)ft_strlen(str) ? 1 : 0;
	if (!st->minus && st->width && (!st->zero || (st->zero && st->dot)))
		printch(st->width - (cn ? st->prec : ft_strlen(str)), ' ', st);
	else if (!st->minus && st->zero && st->width)
		printch(st->width - ft_strlen(str), '0', st);
	if (st->prec)
		printch(st->prec - ft_strlen(str), '0', st);
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - (cn ? st->prec : ft_strlen(str)), ' ', st);
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
	str = ft_strjoin("0x", str);
	free(tmp);
	if (!st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
	ft_putstr(str, st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - ft_strlen(str), ' ', st);
}
