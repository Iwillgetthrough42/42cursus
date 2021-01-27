#include "ft_memcmp.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "abcdefgj";
	char s2[] = "kkkkkkkk";

	printf("%s", ft_memcmp(s1, s2, 8));
	//printf("%zu", strlcat(s, s2, 10));
}
