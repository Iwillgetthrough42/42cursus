#include "ft_strjoin.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "abcdefhijklmn";
	char s2[] = "kljbklkjk";
	printf("%s", ft_strjoin(s1, s2));
	//printf("%s", s);
	//printf("%zu", strlcat(s, s2, 10));
}
