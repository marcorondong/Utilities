#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# include "get_next_line.h"

/*
int main () {
	int fd = open("1char.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}*/

int	main(void)
{
	int			fd;
	const char	*path;

	path = "/nfs/homes/marondon/Documents/"
		"Github/04_get_next_line/Listo/sample.txt";
	fd = open(path, O_RDONLY);
	//fd = open("sample.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}

	char	*line;
	while ((line = get_next_line(fd)) != NULL) // It's a while loop because
					// the file has several lines and line = NULL when EOF
	{
		printf("This is the file text: %s", line); // I print each line
													// in each loop turn
		free(line); // Free the line after you're done with it
	}

	close(fd); // Close the file descriptor when done
	return (0);
}
