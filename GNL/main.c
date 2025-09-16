

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

<<<<<<< HEAD
	fd = open("file1.txt", O_RDONLY);
=======
	fd = open("read1.txt", O_RDONLY);
>>>>>>> d1643e8 (working on a fix)
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
