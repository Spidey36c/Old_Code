# ****************************************************
# Makefile to build test code for user mode threading library
#
# Author: Phil Howard
COPTS=-Wall -g -c -O0 
OBJS=sched.o \

EXES=test1 \
	test2 \
	test3 \
	test4 \
	test5 \

all: $(EXES)

clean:
	rm -f $(OBJS)
	rm -f $(EXES)

%: %.c $(OBJS)
	gcc $@.c $(OBJS) -g -o $@

.c.o:
	gcc $(COPTS) $? -o $@
