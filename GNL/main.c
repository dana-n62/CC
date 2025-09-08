#include "get_next_line.h"
//this code is a helper function to understand how open/read/write works

int	main(void)
{
	int	fd;
	char	*buffer;

	fd = open("read2.txt", O_RDONLY);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(-1);
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
	return (0);
}
