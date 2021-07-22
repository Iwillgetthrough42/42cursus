/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:25:02 by arastepa          #+#    #+#             */
/*   Updated: 2021/02/23 17:21:53 by arastepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_st
{
	int	minus;
	int zero;
	int	dot;
	int	prec;
	int	width;
	int	len;
}				t_fields;

int				ft_printf(const	char *s, ...);
void			printchar(va_list args, t_fields *st);
void			printdigit(char c, va_list args, t_fields *st);
void			printstr(va_list args, t_fields *st);
char			*ft_anybase(unsigned long n, const char *base);
void			printhex(char c, va_list args, t_fields *st);
void			check_flags(char **str, t_fields *st);
void			check_width(char **str, t_fields *st, va_list args);
void			check_precision(char **str, t_fields *st, va_list args);
void			printch(int quant, char ch, t_fields *st);
void			printpointer(va_list args, t_fields *st);
char			*ft_utoa(unsigned long n);
void			ft_putstr(char *str, t_fields *st);

#endif
