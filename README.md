*This project has been created as part of the 42 curriculum by mobenais.*

# get_next_line

A function that reads a file descriptor one line at a time, whatever the
size of the underlying `read()` buffer.

```c
char *get_next_line(int fd);
```

Each call returns the next line (including its trailing `\n`, if any) as a
freshly allocated string, or `NULL` at end of file or on error. The bonus
version keeps one buffer per file descriptor, so several files can be read
alternately.

![get_next_line demo](docs/demo.gif)

## Usage

Drop the files into your project and compile them with your code. The read
chunk size is set at compile time with `BUFFER_SIZE`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int   fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Tests

```sh
make test                   # reads tests/sample.txt with BUFFER_SIZE=42
make test BUFFER_SIZE=1     # any value works, the output is identical
make test_bonus             # bonus build: two files read alternately
```

## Files

```
.
├── get_next_line.c               mandatory part
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c         bonus: one static buffer per fd
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
├── tests/main.c                  demo program
├── tests/sample.txt
└── Makefile                      test targets only (no library to build)
```

## How it works

A static buffer keeps whatever `read()` returned past the end of the current
line. On each call the function:

1. appends `BUFFER_SIZE` bytes at a time to that buffer until it contains a
   newline or `read()` returns 0;
2. extracts everything up to and including the newline as the returned line;
3. keeps the remainder in the static buffer for the next call.

Memory is freed on error and at end of file, so no allocation leaks across
calls.
