# ***
# *** You may modify this file but don't submit it.
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

TESTFLAGS = -DDEBUG

SRCS = main.c hw10.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw10

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

testall: test1 test2 test3 

test1: hw10
	./hw10 6 3 > output1
	diff output1 expected/expected1

test2: hw10
	./hw10 6 4 > output2
	diff output2 expected/expected2

test3: hw10
	./hw10 25 7 > output3
	diff output3 expected/expected3

memory: hw10
# You may consider using other flags for valgrind, such as --leak-check=full, to ensure that your program has absolutely no memory errors
	valgrind ./hw10 12 5

clean: # remove all machine generated files
	rm -f hw10 *.o output? *~

TESTFLAGS = -DDEBUG
