

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("read1.txt", O_RDONLY);

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
