#include "get_next_line.h"
//this code is a helper function to understand how open/read/write works

int	main(void)
{
	int	fd;
	char	*buffer;
	/* fd = open("read2.txt", O_RDWR | O_CREAT, 0744);
	if (fd == -1)
	{
		perror("error");
	}
	ft_putstr_fd("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nMorbi ut ultricies lectus.", fd); */
	fd = open("read2.txt", O_RDWR);
	buffer = get_next_line(fd);
	if (!buffer)
	{
		close(fd);
		return (-1);
	}
	while (buffer != NULL)
	{
		printf("%s\n", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	free(buffer);
	return (0);
}
