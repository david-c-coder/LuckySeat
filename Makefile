LuckySeat: LuckySeat.o
	gcc LuckySeat.o -s -o LuckySeat -mwindows
LuckySeat.o: LuckySeat.c
	gcc -Wall -c -O3 LuckySeat.c
clean:
	rm -f ./*.o
	rm -f ./*.exe