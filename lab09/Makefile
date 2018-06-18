CC = gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror \
	-Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
	-Wbad-function-cast -Wcast-qual -Waggregate-return \
	-fno-diagnostics-show-option -D_POSIX_C_SOURCE=200801L

MKPHONEPROG = mkphone
MKPHONESCRS = mkphone.c
MKPHONEOBJS = $(LAB1SRCS:.c=.o)

LSPHONEPROG = lsphone
LSPHONESCRS = lsphone.c
LSPHONEOBJS = $(LAB1SRCS:.c=.o)

PHONEPROG = phone
PHONESCRS = phone.c
PHONEOBJS = $(LAB1SRCS:.c=.o)

PROGS = $(MKPHONEPROG) $(LSPHONEPROG) $(PHONEPROG)
SRCS = $(PHONEPROG) $(PHONESCRS) $(PHONESCRS)
OBJS = $(SRCS:.c=.o)

all: $(PROGS)

mkphone: $(MKPHONEOBJS)
	$(CC) $(MKPHONEOBJS) -o $(MKPHONEPROG)

lsphone: $(LSPHONEOBJS)
	$(CC) $(LSPHONEOBJS) -o $(LSPHONEPROG)

phone: $(PHONEOBJS)
	$(CC) $(PHONEOBJS) -o $(PHONEPROG)

mkphone.o: mkphone.c

lsphone.o: lsphone.c

phone.o: phone.c 
	
clean:
	rm -f core $(PROGS) $(OBJS)
