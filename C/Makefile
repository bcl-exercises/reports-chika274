getdist: getdist.o mylib.o
	gcc getdist.o mylib.o -o getdist
	./getdist -a genrand.csv		#オプション(-hとか)つければ、平均などの標準出力も可能

getdist.o: getdist.c
	gcc getdist.c -c

mylib.o:  mylib.c
	gcc mylib.c -c

clean:
	rm -f *.o *~ 

