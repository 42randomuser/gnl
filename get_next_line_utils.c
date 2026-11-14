#include "get_next_line.h"
#include <stdint.h>
#include <stdlib.h>

size_t	ft_strlen(char *line)
{
	size_t	len;

	len = 0;
	while (line && line[len])
		len++;
	return (len);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

size_t	ft_linenl(char *stash)
{
	size_t	len;

	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (len);
}

void	ft_rmnl(char *stash)
{
	size_t	read_pos;
	size_t	write_pos;

	read_pos = ft_linenl(stash);
	write_pos = 0;
	while (stash[read_pos])
	{
		stash[write_pos] = stash[read_pos];
		write_pos++;
		read_pos++;
	}
	stash[write_pos] = '\0';
}
