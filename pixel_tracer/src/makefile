DEBUG=yes
CC=gcc
CFLAGS=
LDFLAGS=-lreadline
EXEC=draw
SRC= $(wildcard *.c)
OBJ1= $(SRC:.c=.lin.o)
OBJ2= $(SRC:.c=.win.o)

WCC=x86_64-w64-mingw32-gcc
WINEXE=draw.exe
WIN_INC=-I"../lib/readline/mingw64/include/"
WIN_LIB=-L"../lib/readline/mingw64/lib/"


all: $(EXEC)

$(EXEC): $(OBJ1)
	$(CC) -o $@ $^ $(LDFLAGS)

%.lin.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)




win:$(WINEXE)

$(WINEXE): $(OBJ2)
	$(WCC) -o $@ $^  $(WIN_LIB) $(LDFLAGS)

%.win.o: %.c
	$(WCC) -o $@ -c $< $(CFLAGS) $(WIN_INC)


.PHONY: clean mrproper

indent:
	indent -kr -brf -as -nut -ppi 2 *.c *.h

deploy:
	cp draw ../bin/linux
	strip --strip-debug ../bin/linux/draw
	cp draw.exe ../bin/win
	strip --strip-debug ../bin/win/draw.exe


clean:
	rm -rf *.o
	rm draw
	rm draw.exe
mrproper: clean
	rm -rf $(EXEC)


