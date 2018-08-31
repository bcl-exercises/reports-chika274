getdist: getdist.o mylib.o
	gcc getdist.o mylib.o -o getdist -lm


getdist.o: getdist.c
	gcc getdist.c -c

mylib.o:  mylib.c
	gcc mylib.c -c

clean:
	rm -f *.o *~ 

getdist2: getdist2.o mylib.o
	gcc getdist2.o mylib.o -o getdist2 -lm

getdist2.o: getdist2.c
	gcc getdist2.c -c