#Compiling environment: MSYS2 clang64
LuckySeat: LuckySeat.o
	clang LuckySeat.o -s -o LuckySeat -mwindows
LuckySeat.o: LuckySeat.c
	clang -Wall -c -O3 LuckySeat.c
clean:
	rm -f ./*.o
	rm -f ./*.exe
	rm -f ./result.txt