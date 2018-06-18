CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option -D_POSIX_C_SOURCE=200801L
PROG = exam

SRCS = main.c filter.c
OBJS = $(SRCS:.c=.o)

exam: $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: main.c filter.h

filter.o: filter.c filter.h

clean:
	rm -f core $(PROG) $(OBJS)
