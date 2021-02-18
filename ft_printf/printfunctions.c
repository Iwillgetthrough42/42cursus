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

void	printchar(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
}

void	printdigit(char c, va_list args)
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
	write (1, str, ft_strlen(str));
}

void	printstr(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	write(1, str, ft_strlen(str));
}

void	printhex(char c, va_list args)
{
	unsigned long	n;
	char			*str;

	if (c == 'x' || c == 'X')
		n = va_arg(args, unsigned int);
	else if (c == 'p')
		n = va_arg(args, unsigned long);
	if (c == 'x')
		str = ft_anybase(n, "0123456789abcdef");
	else if (c == 'X')
		str = ft_anybase(n, "0123456789ABCDEF");
	else if (c == 'p')
	{
		str = ft_anybase(n, "0123456789abcdef");
		write(1, "0x", 2);
	}
	write(1, str, ft_strlen(str));
}



