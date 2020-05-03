OBJS	= main.o LZespolona.o MacierzKw.o MacierzKwC.o UkladRownan.o UkladRownanC.o wektor.o wektorC.o
SOURCE	= main.cpp LZespolona.cpp MacierzKw.cpp MacierzKwC.cpp UkladRownan.cpp UkladRownanC.cpp wektor.cpp wektorC.cpp
HEADER	= LZespolona.hh MacierzKw.h UkladRownan.h wektor.h
OUT	= Zad3.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

LZespolona.o: LZespolona.cpp
	$(CC) $(FLAGS) LZespolona.cpp -std=c++14

MacierzKw.o: MacierzKw.cpp
	$(CC) $(FLAGS) MacierzKw.cpp -std=c++14

MacierzKwC.o: MacierzKwC.cpp
	$(CC) $(FLAGS) MacierzKwC.cpp -std=c++14

UkladRownan.o: UkladRownan.cpp
	$(CC) $(FLAGS) UkladRownan.cpp -std=c++14

UkladRownanC.o: UkladRownanC.cpp
	$(CC) $(FLAGS) UkladRownanC.cpp -std=c++14

wektor.o: wektor.cpp
	$(CC) $(FLAGS) wektor.cpp -std=c++14

wektorC.o: wektorC.cpp
	$(CC) $(FLAGS) wektorC.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)

