CC=g++
exe_file=Application

$(exe_file): Application.cpp Wumpus.o Bats.o Escape.o Event.o Game.o Gold.o Pit.o Room.o
	$(CC) Application.cpp Wumpus.o Bats.o Escape.o Event.o Game.o Gold.o Pit.o Room.o -o $(exe_file)

Wumpus.o: Wumpus.cpp Wumpus.h
	$(CC) -c Wumpus.cpp
Bats.o: Bats.cpp Bats.h
	$(CC) -c Bats.cpp
Escape.o: Escape.cpp Escape.h
	$(CC) -c Escape.cpp
Event.o: Event.cpp Event.h
	$(CC) -c Event.cpp
Game.o: Game.cpp Game.h
	$(CC) -c Game.cpp
Gold.o: Gold.cpp Gold.h
	$(CC) -c Gold.cpp
Pit.o: Pit.cpp Pit.h
	$(CC) -c Pit.cpp
Room.o: Room.cpp Room.h
	$(CC) -c Room.cpp

clean: 
	rm -f *.o $(exe_file)