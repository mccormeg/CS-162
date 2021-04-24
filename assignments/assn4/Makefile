Roombaclean.exe: Floor.o Roomba.o RandomRoomba.o BetterRoomba.o SuperRoomba.o main.o
	g++ Floor.o Roomba.o RandomRoomba.o BetterRoomba.o SuperRoomba.o main.o
Floor.o: Floor.cpp
	g++ -c Floor.cpp
Roomba.o: Roomba.cpp
	g++ -c Roomba.cpp
RandomRoomba.o: RandomRoomba.cpp
	g++ -c RandomRoomba.cpp
BetterRoomba.o: BetterRoomba.cpp
	g++ -c BetterRoomba.cpp
SuperRoomba.o: SuperRoomba.cpp
	g++ -c SuperRoomba.cpp
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o *.exe

