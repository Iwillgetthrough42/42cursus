#include <stdarg.h>
#include "lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void 	init(t_fields *st)
{
	st->width = 0;
	st->prec = 0;
	st->dot = 0;
	st->len = 0;
}

static	int		count(unsigned long n, unsigned int basesize)
{
	int count;

	count = (n > 0 ? 0 : 1);
	while (n != 0)
	{
		n /= basesize;
		count++;
	}
	return (count);
}

char			*ft_anybase(unsigned long n, char *base)
{
	unsigned	int	base_size;
	int				cnt;
	char			*new;
	int				i;

	base_size = ft_strlen(base);
	cnt = count(n, base_size);
	if (!(new = malloc(sizeof(char) * (cnt + 1))))
		return (0);
	new[cnt] = '\0';
	i = 0;
	if (n == 0)
		new[cnt - i - 1] = '0';
	while (n != 0)
	{
		new[cnt - i - 1] = base[n % base_size];
		n /= base_size;
		i++;
	}
	return (new);
}

static	int		cnt(long n)
{
	size_t	cnt;

	cnt = (n > 0 ? 0 : 1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static	char	*reverse(char *str)
{
	size_t	k;
	size_t	i;
	char	tmp;

	if (ft_strlen(str) % 2 == 0)
	{
		k = ft_strlen(str) / 2;
	}
	else
	{
		k = (ft_strlen(str) + 1) / 2;
	}
	i = 0;
	while (i < k)
	{
		tmp = str[i];
		str[i] = str[ft_strlen(str) - 1 - i];
		str[ft_strlen(str) - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char			*ft_utoa(long n)
{
	size_t	i;
	char	*str;
	int		t;
	long	num;

	num = n;
	t = 0;
	if (!(str = (char *)malloc((cnt(num) + 1) * sizeof(char))))
		return (NULL);
	if (num < 0)
	{
		*str++ = '-';
		num *= -1;
		t = 1;
	}
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (num != 0)
	{
		str[i++] = (num % 10 + '0');
		num = num / 10;
	}
	str[i] = '\0';
	return (reverse(str) - t);
}



char	*ft_substr(char *str, int start, int len)
{
	char *dst;
	int i;

	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	if (ft_strlen(str) > start)
	{	
		while (i < start + len)
		{
			dst[i - start] = str[i];
			i++;
		}
	}
	dst[i - start] = '\0';
	return (dst);
}

char	*ft_strdup(char *str)
{
	char *dst;
	int i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (i < ft_strlen(str))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	printch(int cnt, char c, t_fields *st)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		write(1, &c, 1);
		st->len += 1;
		i++;
	}
}

void	checkwidth(char **s, t_fields *st)
{
	while (**s >= '0' && **s <= '9')
	{	
		st->width =  (st->width * 10) + (**s - '0');
		(*s)++;
	}
}

void checkprec(char **s, t_fields *st)
{
	if (**s == '.')
	{
		st->dot = 1;
		(*s)++;
		while (**s >= '0' && **s <= '9')
		{	
			st->prec =  (st->prec * 10) + (**s - '0');
			(*s)++;
		}
	}
}

void	ft_putstr(char *str, t_fields *st)
{
	write(1, str, ft_strlen(str));
	st->len += ft_strlen(str);
}

void	printstr(t_fields *st, va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (st->dot)
		str = ft_substr(str, 0, st->prec);
	if (st->width)
		printch(st->width - ft_strlen(str), ' ', st);
	ft_putstr(str, st);
}

void	printdigit(t_fields *st, va_list args)
{
	int num;
	int cn;
	char *str;
	int uns;
	int t;

	num = va_arg(args, int);
	if (num < 0)
		uns = -1 * num;
	else
		uns = num;
	t = (num < 0 ? 1 : 0);
	str = ((num == 0 && st->dot) ? "" : ft_anybase(uns, "0123456789"));
	cn = st->prec >= (int)ft_strlen(str) ? 1 : 0;
	if (st->width)
		printch(st->width - ((cn ? st->prec + t : ft_strlen(str) + t)) , ' ', st);
	if (num < 0)
		printch(1, '-', st);
	if (st->dot)
		printch(st->prec - ft_strlen(str) , '0', st);
	//if (num < 0 && st->dot)
		//str++;
	ft_putstr(str, st);
}


void	printhex(t_fields *st, va_list args)
{
	int num;
	int cn;
	char *str;

	num = va_arg(args, unsigned int);
	str = ((num == 0 && st->dot) ? "" : ft_anybase(num, "0123456789abcdef"));
	cn = st->prec >= (int)ft_strlen(str) ? 1 : 0;
	if (st->width)
		printch(st->width - ((cn ? st->prec : ft_strlen(str))) , ' ', st);
	if (num < 0 && st->dot)
		printch(1, '-', st);
	if (st->dot)
		printch(st->prec - ft_strlen(str) , '0', st);
	if (num < 0 && st->dot)
		str++;
	ft_putstr(str, st);
}

void 	handle_signs(char c, t_fields *st, va_list args)
{
	if (c == 's')
		printstr(st, args);
	else if (c == 'd')
		printdigit(st, args);
	else if (c == 'x')
		printhex(st, args);
}

void 	checksign(char **s, t_fields *st, va_list args)
{
	char *signs;
	int j;

	(*s)++;
	checkwidth(s, st);
	checkprec(s, st);
	signs = ft_strdup("sdx");
	j = 0;
	while (signs[j] != '\0')
	{	
		if (**s == signs[j])
		{	
			handle_signs(signs[j], st, args);
			break ;
		}
		j++;
	}
}

int ft_printf(char *s, ...)
{
	va_list args;
	t_fields st;
	int i;

	i = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		init(&st);
		if (*s == '%')
			checksign(&s, &st, args);
		else
			printch(1, *s, &st);
		s++;
	}
	return (0);
}

int main()
{
	printf("%10.2x\n", 100);
	ft_printf("%10.2x", 100);
}
