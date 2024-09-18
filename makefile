WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = 

SRCS = a4.c
OBJS = $(SRCS:%.c=%.o)

a4: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o a4

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

test: a4

memory: a4
	valgrind --tool=memcheck ./a4

clean: # remove all machine generated files
	rm -f a4 *.o output? *~