/*
** Reads every line of the files given on the command line (or
** tests/sample.txt by default) and prints them with their line number.
** With the bonus build, two files are read alternately to show that
** one static buffer per file descriptor is kept.
**
** build: make test  /  make test_bonus
*/
#ifdef BONUS
# include "get_next_line_bonus.h"
#else
# include "get_next_line.h"
#endif
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[32m"
#define DIM   "\033[2m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"

static void	read_file(const char *path)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		return ;
	}
	printf(BOLD "%s" RESET DIM "  (BUFFER_SIZE=%d)" RESET "\n", path, BUFFER_SIZE);
	n = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf(GREEN "%3d" RESET " | %s", ++n, line);
		if (line[0] && line[strlen(line) - 1] != '\n')
			printf(DIM "  <no newline>" RESET "\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf(DIM "EOF after %d lines" RESET "\n\n", n);
}

#ifdef BONUS
static void	read_interleaved(const char *a, const char *b)
{
	int		fa;
	int		fb;
	char	*la;
	char	*lb;

	fa = open(a, O_RDONLY);
	fb = open(b, O_RDONLY);
	printf(BOLD "interleaved reads: %s / %s" RESET "\n", a, b);
	la = get_next_line(fa);
	lb = get_next_line(fb);
	while (la || lb)
	{
		if (la)
			printf(GREEN "A" RESET " | %s", la);
		if (lb)
			printf(GREEN "B" RESET " | %s", lb);
		free(la);
		free(lb);
		la = (la) ? get_next_line(fa) : NULL;
		lb = (lb) ? get_next_line(fb) : NULL;
	}
	close(fa);
	close(fb);
}
#endif

int	main(int argc, char **argv)
{
	int	i;

	setvbuf(stdout, NULL, _IONBF, 0);
	if (argc < 2)
		read_file("tests/sample.txt");
	i = 1;
	while (i < argc)
		read_file(argv[i++]);
#ifdef BONUS
	read_interleaved("tests/sample.txt", "Makefile");
#endif
	return (0);
}
