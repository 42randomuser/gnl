#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *line);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_linenl(char *stash);
void	ft_rmnl(char *stash);

#endif
