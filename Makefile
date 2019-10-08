CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra -g

# Connects files to create executable

skipbo: main.cpp Player.o Pile.o main.o Pile.o DrawPile.o BuildPile.o Card.o FaceUpPile.o SkipBoGame.o Hand.o 
	$(CC) -o skipbo main.o Player.o Pile.o DrawPile.o BuildPile.o Card.o FaceUpPile.o SkipBoGame.o Hand.o

main.o: main.cpp
	$(CC) -c main.cpp

# Create Pile.o by compiling Pile.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp

SkipBoGame.o: SkipBoGame.cpp SkipBoGame.h
	$(CC) $(CFLAGS) -c SkipBoGame.cpp

Pile.o: Pile.cpp Pile.h
	$(CC) $(CFLAGS) -c Pile.cpp

DrawPile.o: DrawPile.cpp DrawPile.h
	$(CC) $(CFLAGS) -c DrawPile.cpp

FaceUpPile.o: FaceUpPile.cpp FaceUpPile.h
	$(CC) $(CFLAGS) -c FaceUpPile.cpp

BuildPile.o: BuildPile.cpp BuildPile.h
	$(CC) $(CFLAGS) -c BuildPile.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) $(CFLAGS) -c Hand.cpp 
# Removes all object files and executables so start again

clean:
	rm -f *.o skipbo
