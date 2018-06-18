CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option -D_POSIX_C_SOURCE=200801L
PROG = calculator

SRCS = main.c
OBJS = $(SRCS:.c=.o)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: main.c 


clean:
	rm -f core $(PROG) $(OBJS)
