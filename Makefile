# get_next_line has no library target: the .c files are meant to be dropped
# into another project. This Makefile only builds the demo/test programs.

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRCS        = get_next_line.c get_next_line_utils.c
SRCS_BONUS  = get_next_line_bonus.c get_next_line_utils_bonus.c

all: test

test: tests/run_tests
	./tests/run_tests

test_bonus: tests/run_tests_bonus
	./tests/run_tests_bonus

tests/run_tests: $(SRCS) tests/main.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I. $(SRCS) tests/main.c -o $@

tests/run_tests_bonus: $(SRCS_BONUS) tests/main.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D BONUS -I. $(SRCS_BONUS) tests/main.c -o $@

clean:
	rm -f tests/run_tests tests/run_tests_bonus

fclean: clean

re: fclean all

.PHONY: all test test_bonus clean fclean re
