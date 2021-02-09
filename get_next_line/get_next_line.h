#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef	struct		s_list
{
	char			*read;
	struct s_list	*next;
}					t_list;

char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					get_next_line(int fd, char **line);

#endif
