

#include "get_next_line.h"

int	main(void)
{
	int	fd;
//	int i = 0;
	char	*line;

	fd = open("read.txt", O_RDWR);
	line = get_next_line(fd);

	while (line != NULL)
	{
		//i++;
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
