CC=gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0`

PROG = browser
SRCS = exam3.c browser.c
OBJS = $(SRCS:.c=.o)


$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

exam3.o: exam3.c browser.h

browser.o: browser.c browser.h

clean:
	rm -f core $(PROG) $(OBJS)

