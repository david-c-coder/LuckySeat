#Compiling environment: MSYS2 clang64

CC=clang
CXX=clang++
CFLAGS=-Wall -c -O3
LDFLAGS=-s -mwindows

src=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(src))
target=LuckySeat.exe

$(target):$(obj)
	$(CC) $(obj) $(LDFLAGS) -o $(target)
            
%.o:%.c
	$(CC) $< $(CFLAGS)

.PHONY:clean    
clean:
	rm -f $(obj) $(target) result.txt
