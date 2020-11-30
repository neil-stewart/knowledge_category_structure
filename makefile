#CFLAGS = -Wall -pedantic -std=c99 -O3
CFLAGS = -Wall -pedantic -std=c99 -g

test: test.o RJM.o
	gcc -o test test.o RJM.o -lm -lgsl -lgslcblas

RJM.o: RJM.c RJM.h defines.h
	gcc $(CFLAGS) -c RJM.c 

test.o: test.c RJM.h defines.h
	gcc $(CFLAGS) -c test.c

clean:
	-rm *.o
	-rm test 
