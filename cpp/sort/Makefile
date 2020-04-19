sort : sort.o mergesort.o quicksort.o
	cc -o sort sort.o quicksort.o mergesort.o

sort.o : sort.c
	cc -c sort.c

mergesort.o : mergesort/mergesort.c
	cc -c mergesort/mergesort.c 

quicksort.o : quicksort/quicksort.c
	cc -c quicksort/quicksort.c

clean : 
	rm sort
	rm *.o
