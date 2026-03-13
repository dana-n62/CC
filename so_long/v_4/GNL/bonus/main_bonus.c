
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return 1;
    }

    char *line1, *line2, *line3;

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);

        if (!line1 && !line2 && !line3) // all finished
            break;

        if (line1) { printf("fd1: %s", line1); free(line1); }
        if (line2) { printf("fd2: %s", line2); free(line2); }
        if (line3) { printf("fd3: %s", line3); free(line3); }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
