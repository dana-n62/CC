

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

	fd = 0;
	line = get_next_line(fd);

	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
