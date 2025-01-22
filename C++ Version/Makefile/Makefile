main: main.o Snake_Game.o Board.o Snake.o Snake_Cell.o
	g++ main.o Snake_Game.o Board.o Snake.o Snake_Cell.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

Snake_Game.o: Snake_Game.cpp
	g++ -c Snake_Game.cpp -o Snake_Game.o

Board.o: Board.cpp
	g++ -c Board.cpp -o Board.o

Snake.o: Snake.cpp
	g++ -c Snake.cpp -o Snake.o

Snake_Cell: Snake_Cell.cpp
	g++ -c Snake_Cell.cpp -o Snake_Cell.o

rm:
	rm *.o main
