

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open("read1.txt", O_RDONLY);

	line = get_next_line(fd);

	int i = 0;
	while (line != NULL)
	{
		printf("%i: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
