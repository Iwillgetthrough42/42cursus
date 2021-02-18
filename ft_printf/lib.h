#ifndef LIB_H
# define LIB_H
# include <stdarg.h>
# include <unistd.h>

typedef struct st
{
	int	minus;
	int zero;
	int	dot;
	int	precision;
	int	width;
}				fl_st;


void	printchar(va_list args); 
void	printdigit(char c, va_list args);
void	printstr(va_list args);
char	*ft_anybase(unsigned long n, const char *base);
void	printhex(char c, va_list args);

#endif
