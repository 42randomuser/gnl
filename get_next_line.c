#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_strcpy(char *line, char *stash, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
}

static ssize_t	ft_read(int fd, char *stash)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (bytes_read <= 0)
		stash[0] = '\0';
	else
		stash[bytes_read] = '\0';
	return (bytes_read);
}

static char	*ft_substr(char *stash, size_t len, char *line)
{
	size_t	line_len;
	char	*new_line;

	line_len = ft_strlen(line);
	new_line = ft_calloc(1, line_len + len + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(new_line, line, line_len);
	ft_strcpy(new_line + line_len, stash, len);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && (!line || line[ft_strlen(line) - 1] != '\n'))
	{
		if (stash[0] == '\0')
			bytes_read = ft_read(fd, stash);
		if (bytes_read > 0)
		{
			line = ft_substr(stash, ft_linenl(stash), line);
			if (!line)
				bytes_read = -1;
			ft_rmnl(stash);
		}
	}
	if (bytes_read < 0)
		free(line);
	if (bytes_read < 0)
		return (NULL);
	return (line);
}
