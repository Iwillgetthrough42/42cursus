#include <stdlib.h>$
#include <sys/types.h>$
#include <sys/uio.h>$
#include <unistd.h>$
#include <stdio.h>$
$
int  ft_strlen(char *s)$
{$
	int i;$
$
	i = 0;$
	while (s[i] != '\0')$
		i++;$
	return (i);$
}$
$
char *ft_strjoin(char *s1, char *s2)$
{$
	char *dst;$
	int i;$
$
	if (!(dst = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))$
		return (NULL);$
	i = 0;$
	while (s1[i] != '\0')$
	{$
		dst[i] = s1[i];$
		i++;$
	}$
	i = 0;$
	while (s2[i] != '\0')$
	{$
		dst[i + ft_strlen(s1)] = s2[i];$
		i++;$
	}$
	dst[i + ft_strlen(s1)] = '\0';$
	free(s1);$
	return (dst);$
}$
$
char *ft_strdup(char *s)$
{$
	int i;$
	char *dst;$
$
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s) + 1))))$
		return (NULL);$
	i = 0;$
	while (s[i] != '\0')$
	{$
		dst[i] = s[i];$
		i++;$
	}$
	dst[i] = '\0';$
	return (dst);$
}$
$
int 	ft_strchr(char *s, char c)$
{$
	int i;$
$
	i = 0;$
	while (s[i] != '\0')$
	{$
		if (s[i] == c)$
			return (i);$
		i++;$
	}$
	if (s[i] == c)$
		return (i);$
	return (0);$
}$
$
char 	*ft_substr(char *s, int start, int len)$
{$
	int i;$
	char *dst;$
$
	if (!(dst = malloc(sizeof(char) * (len + 1))))$
		return (NULL);$
	i = start;$
	while (i < len)$
	{$
		dst[i - start] = s[i];$
		i++;$
	}$
	dst[i - start] = '\0';$
	return (dst);$
}$
$
int get_next_line(char **line)$
{$
	int i;$
	char buf[2];$
	char *tmp;$
$
	*line = ft_strdup("");$
	while ((i = read(0, buf, 1)) > 0)$
	{$
		buf[i] = '\0';$
		*line = ft_strjoin(*line, buf);$
		if (ft_strchr(*line, '\n'))$
		{$
			tmp = *line;$
			*line = ft_substr(*line, 0, ft_strchr(*line, '\n'));$
			free(tmp);$
			break ;$
		}$
	}$
if (i < 0)$
	return (-1);$
 if (!i)$
		return (0);$
	return (1);$
}$
$
int main(void)$
{$
	int		r;$
	char	*line;$
$
	//get_next_line(&line);$
$
	//printf("%s", line);$
$
	line = NULL;$
	//printf("===================================================\n");$
	while ((r = get_next_line(&line)) > 0)$
	{	$
		printf("%s\n", line);$
		free(line);$
		line = NULL;$
	}$
	printf("%s", line);$
	free(line);$
	line = NULL;$
	//printf("===================================================\n");$
}$
