getdist: getdist.o mylib.o
	gcc getdist.o mylib.o -o getdist
	# ./getdist -a genrand.csv		#オプション(-hとか)つければ、平均などの標準出力も可能

getdist.o: getdist.c
	gcc getdist.c -c

mylib.o:  mylib.c
	gcc mylib.c -c

clean:
	rm -f *.o *~ 

getdist2: getdist2.o mylib.o
	gcc getdist2.o mylib.o -o getdist2
	# ./genrand 100 | getdist2		#オプション(-hとか)つければ、平均などの標準出力も可能

getdist2.o: getdist2.c
	gcc getdist2.c -c