all: sig.c
	gcc sig.c -o signal
run: all
	./signal
clean:
	rm -f *~
	rm -f *.o
