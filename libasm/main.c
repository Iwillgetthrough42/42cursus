#include "libasm.h"

void	checkstrlen()
{
	printf("### FT_STRLEN ###\n");
	printf("   strlen: %zu\n", strlen("abcdef"));
	printf("ft_strlen: %zu\n", ft_strlen("abcdef"));
}

void	checkstrcpy()
{
	char *str1;
	char *str2;

	printf("### FT_STRCPY ###\n");
	str1 = strdup("ppp");
	str2 = strdup("ppp");
	str1 = strcpy(str1, "lllllllll");
	str2 = ft_strcpy(str2, "lllllllll");
	printf("   strcpy: %s\n", str1);
	printf("ft_strcpy: %s\n", str2);
}

void	checkstrcmp()
{
	char *s;

	s = "eeee";
	printf("### FT_STRCMP ###\n");
	printf("ft_strcmp: %d\n", ft_strcmp(s, "llll"));
	printf("   strcmp: %d\n", strcmp(s, "llll"));

}

void	checkwrite()
{
	char c;

	printf("### FT_WRITE ###\n");
	printf(" -   write: %zd\n", write(0, &c, 1));
	printf(" - ft_write: %zd\n", ft_write(0, &c, 1));
}

void	checkread()
{
	printf("### FT_READ ###\n");
	printf(" -   read: %zd\n", read(0, "ab", 2));
	printf(" - ft_read: %zd\n", ft_read(0, "ab", 2));
}

void	checkstrdup()
{
	printf("### FT_STRRDUP ###\n");
	printf("   strdup: %s\n", strdup("llll"));
	printf("ft_strdup: %s\n", ft_strdup("llll"));
}

int		main()
{
	checkstrlen();
	checkstrcpy();
	checkstrcmp();
	checkwrite();
	checkread();
	checkstrdup();
}