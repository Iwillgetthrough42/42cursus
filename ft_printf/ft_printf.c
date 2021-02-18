/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:02:01 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/17 17:52:11 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"
#include <stdio.h>

void	init_struct(fl_st st)
{
	st.minus = 0;
	st.zero = 0;
	st.precision = 0;
	st.asterisk = 0;
	st.width = 0;
}

void	handle_signs(char c, va_list args)
{
	if (c == 'c')
		printchar(args);
	else if (c == 'd' || c == 'i' || c == 'u')
		printdigit(c, args);
	else if (c == 's')
		printstr(args);
	else if (c == 'x' || c == 'X' || c == 'p')
		printhex(c, args);
}

void	check_sign(const char *s, va_list args, int i)
{
	char	*signs;
	int		j;
	char	*str;

	j = 0;
	signs = ft_strdup("cspdiuxX");
	while (signs[j] != '\0')
	{
		if (s[i + 1] == signs[j])
		{
			handle_signs(signs[j], args);
			break ;
		}
		j++;	
	}
}

void		ft_printf(const char *s, ...)
{
	char	c;
	int		i;

	fl_st st;
	init_struct(st);
	i = 0;
	va_list args;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			check_sign(s, args, i);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}

}

int main()
{
	int k;
	int *p;

	k = 325;
	p = &k;
	ft_printf("number is :%c,   other number is: %p, kkkkkkk: %s",'b', p, "lllll");
}
